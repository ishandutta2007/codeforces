#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	using ll = long long;
	int n;
	cin >> n;
	vector<vector<ll> > a(n, vector<ll>(n, 0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ll val = ll(i & 1) << (i + j);
			a[i][j] = val;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << flush;
	int q;
	cin >> q;
	for(int j = 0; j < q; j++){
		ll val;
		cin >> val;
		vector<pair<int,int> > path;
		pair<int,int> cur = {0, 0};
		while(cur.first < n-1 || cur.second < n-1){
			path.push_back(cur);
			if(cur.first == n-1){
				cur.second += 1;
			} else if(cur.second == n-1){
				cur.first += 1;
			} else {
				int d = cur.first + cur.second + 1;
				if((1ll << d) & val){
					if(cur.first & 1){
						cur.second += 1;
					} else {
						cur.first += 1;
					}
				} else {
					if(cur.first & 1){
						cur.first += 1;
					} else {
						cur.second += 1;
					}					
				}
			}
		}
		path.push_back(cur);
		for(pair<int,int> d : path){
			cout << d.first + 1 << ' ' << d.second + 1 << '\n';
		}
		cout << flush;
	}
}