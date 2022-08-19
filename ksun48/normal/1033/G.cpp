#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

pair<LL,LL> solve_slow(LL n, LL m, vector<LL> v){
	LL wf = 0;
	LL ws = 0;
	for(LL a_ = 1; a_ <= m; a_++){
		for(LL b_ = 1; b_ <= m; b_++){
			LL a = a_;
			LL b = b_;
			if(a > b) swap(a,b);
			vector<LL> w = v;
			for(LL i = 0; i < n; i++){
				w[i] %= (a+b);
			}
			sort(w.begin(), w.end());
			if(2 * a <= b){
				LL numb = 0;
				LL numa = 0;
				for(LL z : w){
					if(z >= b){
						numb++;
					} else if(z >= a){
						numa++;
					}
				}
				if(numb == 0 && numa == 0){
					ws++;
				} else if(numb == 1 && numa == 0){
					wf++;
				}
			} else if(b < 2*a){
				LL num2a = 0;
				LL numb = 0;
				LL numa = 0;
				for(LL z : w){
					if(z >= 2*a){
						num2a++;
					} else if(z >= b){
						numb++;
					} else if(z >= a){
						numa++;
					}
				}
				if(num2a == 1 && numb % 2 == 0 && numa == 0){
					if(numb > 0){
						cerr << a_ << " " << b_ << endl;
					}
					wf++;
				} else if(num2a == 0 && numa == 0){
					if(numb % 2){
						wf++;
					} else {
						ws++;
					}
				}
			}
		}
	}
	return {wf, ws};
}

pair<LL,LL> solve(LL n, LL m, vector<LL> v){
	LL wf = 0;
	LL ws = 0;
	for(LL s = 2; s <= 2*m; s++){
		vector<LL> w = v;
		for(LL i = 0; i < n; i++){
			w[i] %= s;
		}
		sort(w.begin(), w.end());
		// assume a <= b
		LL mina = max(1LL, s - m);
		LL maxa = s / 2;
		// subtract overcount
		if(s % 2 == 0){
			LL num = 0;
			for(LL i = 0; i < n; i++){
				num += (w[i] >= (s/2));
			}
			if(num % 2){
				wf--;
			} else {
				ws--;
			}
		}
		// check maxa -> mina
		// b = s-a
		{
			{
				LL i1 = mina;
				i1 = max(i1, w.back() + 1);
				LL i2 = s/3;
				if(i1 <= i2) ws += 2*(i2 - i1 + 1);
			}
			{
				LL i1 = mina;
				LL i2 = s/3;
				if(w.size() > 1) i1 = max(i1, w[w.size()-2] + 1);
				i1 = max(i1, s - w.back());
				if(i1 <= i2) wf += 2*(i2 - i1 + 1);
			}
		}
		{
			{
				LL i1 = max(mina, s/3 + 1);
				LL i2 = maxa;
				i2 = min(i2, w.back()/2);
				if(w.size() > 1) i1 = max(i1, w[w.size()-2] / 2 + 1);
				LL cnt = 0;
				for(LL a = 0; a + 1 < w.size(); a++){
					LL z = w[a];
					if(z * 2 >= s) cnt++;
					if(z * 2 >= s){
						i1 = max(i1, s - z);
					} else {
						i1 = max(i1, z + 1);
					}
				}
				if(i1 <= i2){
					if(cnt % 2 == 0){
						wf += 2*(i2 - i1 + 1);
					}
				}
			}
			{
				LL i1 = max(mina, s/3 + 1);
				LL i2 = maxa;
				i1 = max(i1, w.back() / 2 + 1);
				LL cnt = 0;
				for(LL a = 0; a < w.size(); a++){
					LL z = w[a];
					if(z * 2 >= s) cnt++;
					if(z * 2 >= s){
						i1 = max(i1, s - z);
					} else {
						i1 = max(i1, z + 1);
					}
				}
				if(i1 <= i2){
					if(cnt % 2){
						wf += 2*(i2 - i1 + 1);
					} else {
						ws += 2*(i2 - i1 + 1);
					}
				}
			}
		}
	}
	return {wf, ws};
}
int main(){
	LL n, m;
	cin >> n >> m;
	vector<LL> v(n);
	for(LL i = 0; i < n; i++){
		cin >> v[i];
	}
	//assert(solve_slow(n, m, v) == solve(n, m, v));
	pair<LL,LL> ans = solve(n, m, v);
	LL wf = ans.first;
	LL ws = ans.second;
	LL wa, wb;
	wa = wb = (m*m - wf - ws) / 2;
	cout << wa << " " << wb << " " << wf << " " << ws << endl;
}