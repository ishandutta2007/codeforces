#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n);
	vector<ll> b(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];

	vector<bool> okay(n, false);

	ll tot = 0;
	for(ll x : a){
		int eq = 0;
		for(int i = 0; i < n; i++){
			if(x == a[i]) eq++;
		}
		if(eq >= 2){
			for(int i = 0; i < n; i++){
				if((x & a[i]) == a[i]){
					okay[i] = true;
				}
			}
		}
	}
	for(int i = 0; i < n; i++) if(okay[i]) tot += b[i];
	cout << tot << '\n';
}