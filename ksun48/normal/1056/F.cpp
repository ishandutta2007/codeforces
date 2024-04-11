#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

double minv[100 + 1][1000 + 1];
void solve(){
	vector<double> powp(1100);
	powp[0] = 1.0;
	for(int i = 1; i < powp.size(); i++){
		powp[i] = 10.0/9.0 * powp[i-1];
	}
	int n;
	cin >> n;
	double C, T;
	cin >> C >> T;
	vector<pair<LL,LL> > probs(n);
	for(int i = 0; i < n; i++){
		cin >> probs[i].first >> probs[i].second;
	}
	sort(probs.begin(), probs.end());
	reverse(probs.begin(), probs.end());

	LL maxscore = 10 * n;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= maxscore; j++){
			minv[i][j] = 1e80;
		}
	}
	minv[0][0] = 0;
	for(int p = 0; p < n; p++){
		int val = probs[p].second;
		double a = probs[p].first;
		for(int i = n; i > 0; i--){
			for(int j = maxscore; j >= 0; j--){
				minv[i][j] = min(minv[i][j], minv[i-1][max(0, j-val)] + a * powp[i]);
			}
		}
	}
	LL s = 0; // can
	LL e = maxscore + 1;
	while(s + 1 < e){
		LL score = (s + e) / 2;
		int ok = 0;
		for(LL i = 0; i <= n; i++){
			double num = minv[i][score];
			double total = T - 10.0 * (double)(i);
			if(total < 0) continue;
			if(num <= total){
				ok = 1;
			} else {
				double t = (sqrt(C * num) - 1) / C;
				if(t >= 0){
					if(t + num / (1 + C * t) <= total){
						ok = 1;
					}
				}
			}
		}
		if(ok){
			s = score;
		} else {
			e = score;
		}
	}
	cout << s << '\n';
}

int main(){
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		solve();
	}
}