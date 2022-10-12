/**
 *    author:  Mohamed.Abo_Okail
 *    created: 23/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	
	int n; cin >> n;
	vector <int> v(n);
	int mx = 0;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mx = max(mx, v[i]);
	}
	for (int i = 0; i < n; i++) {
		ans += (mx - v[i]);
	}
	cout << ans << endl;
}