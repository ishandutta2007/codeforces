#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, a, b;
	cin >> n >> a >> b;
	if(abs(a-b) > 1){
		cout << -1 << '\n';
		return;
	}
	if(a + b > n-2){
		cout << -1 << '\n';
		return;
	}
	int c = 0;
	int d = n-1;
	vector<int> res;
	if(a >= b){
		res = {0};
		c++;
		while(a || b){
			if(a > 0){
				res.push_back(d);
				a--;
				d--;
			}
			if(b > 0){
				res.push_back(c);
				b--;
				c++;
			}
		}
	} else {
		res = {n-1};
		d--;
		while(a || b){
			if(b > 0){
				res.push_back(c);
				b--;
				c++;
			}
			if(a > 0){
				res.push_back(d);
				a--;
				d--;
			}
		}
	}
	if(res.back() == c-1){
		for(int j = c; j <= d; j++) res.push_back(j);
	} else {
		for(int j = d; j >= c; j--) res.push_back(j);		
	}
	for(int x : res) cout << (x+1) << ' ';
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}