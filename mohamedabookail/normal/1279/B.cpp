/**
 *    author:  Mohamed.Abo_Okail
 *    created: 27/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"
 
int main()
{
	std::ios_base::sync_with_stdio(0);
	ll t; cin >> t;
	while(t--) {
		ll n, s; cin >> n >> s;
		vector <ll> v(n);
		ll sum = 0, ans = 0, x = s, y = s, z = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			sum += v[i];
		}
		if(sum <= s) {
			cout << 0 << endl;
			continue;
		}
		for (int i = 1; i < n; i++) {
			if(v[i] < v[ans]) {
				if(s >= v[i]) {
					s -= v[i];
				}
				else { break; }
				
			}
			else {
				if(s >= v[ans]) {
					s -= v[ans];
					ans = i;
				}
				else { break; }
			}
		}

		for (int i = 0; i < ans; i++) {
			z += v[i];
		} x -= z;
		if((ans + 1) < n && v[ans + 1] > x) {
			cout << 0 << endl;
		}
		else if(n == 1 && y < v[0]) {
			cout << 0 << endl;
		}
		else if(n >= 2 && y < v[0] && y < v[1]) {
			cout << 0 << endl;
		}
		else {
			cout << ans + 1 << endl;
		}
	}
}