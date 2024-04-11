#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	using ll = long long;
	vector<vector<ll> > a(n, vector<ll>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		int j = (i + 1) % n;
		int k = (j + 1) % n;
		ll v = a[i][k] * a[i][j] / a[k][j];
		ll s = 0;
		ll e = ll(sqrt(v)) + 4;
		while(s + 1 < e){
			ll m = (s + e) / 2;
			ll g = m * m;
			if(g <= v){
				s = m;
			} else {
				e = m;
			}
		}
		cout << s << ' ';
	}
	cout << '\n';
}