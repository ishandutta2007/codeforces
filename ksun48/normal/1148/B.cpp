#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll n, m, ta, tb;
	int k;
	cin >> n >> m >> ta >> tb >> k;
	vector<ll> a(n);
	vector<ll> b(m);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i] += ta;
	}
	for(int i = 0; i < m; i++){
		cin >> b[i];
	}
	if(n <= k || m <= k){
		cout << -1 << '\n';
		exit(0);
	}
	ll best = 0;
	for(int c = 0; c <= k; c++){
		ll fl = a[c];
		int s = -1;
		int e = m;
		while(s + 1 < e){
			int mid = (s + e) / 2;
			if(b[mid] >= fl){
				e = mid;
			} else {
				s = mid;
			}
		}
		int z = e + k - c;
		if(z >= m){
			best = 1e17;
		} else {
			best = max(best, b[z]);
		}
	}
	if(best > (ll)1e15){
		cout << -1 << '\n';
	} else {
		cout << best + tb << '\n';
	}
}