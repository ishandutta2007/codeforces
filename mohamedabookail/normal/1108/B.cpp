/**
 *    author:  Mohamed.Abo_Okail
 *    created: O2/O1/2O2O
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	int n, mx = -1; cin >> n;
	vector <int> v(n);
	map <int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mx = max(mx, v[i]);
	}
	for (int i = 0; i < n; i++) {
		if(!(mx % v[i])) {
			if(mp[v[i]] == 0) {
				mp[v[i]]++;
				v[i] = 0;
			}
		}
	}
	sort(v.begin(), v.end());
	cout << mx << ' ' << v[n - 1] << endl;
}