/**
 *    author:  Mohamed.Abo_Okail
 *    created: 29/12/2019
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
		ll m; cin >> m;
		vector <ll> v(m);
		bool k = false;
		for (int i = 0; i < m; i++) {
			cin >> v[i];
		}
		for (int i = 1; i < m; i++) {
			if(abs(v[i] - v[i - 1]) > 1) {
				k = true;
			}
		}
		if(!k) { cout << "NO" << endl; }
		else {
			cout << "YES" << endl;
			for (int i = 1; i < m; i++) {
				if(abs(v[i] - v[i - 1]) > 1) {
					cout << i << ' ' << (i + 1) << endl;
					break;
				}
			}
		}
	}
}