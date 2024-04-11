/**
 *    author:  Mohamed.Abo_Okail
 *    created: 31/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	ll n; cin >> n;
	vector <ll> v(n);
	ll cnt = 0, x = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if(v[i] >= 0) { v[i] = (-v[i] -1); }
		if(v[i] < 0) { cnt++; }
		x = min(x, v[i]);
	}
	if(cnt % 2) {
		for (int i = 0; i < n; i++) {
			if(v[i] == x) {
				v[i] = (-v[i] - 1);
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
	} cout << endl;
}