/**
*    author:  Mohamed Abo Okail
*    created: 13/O4/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	ll n, q; cin >> n >> q;
	vector < int > a(n);
	map < int, int > mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if(!mp[a[i]]) {
			mp[a[i]] = i + 1;
		}
	}
	
	while(q--) {
		int x; cin >> x;
		int cur = mp[x];
		cout << cur << ' ';
		for(auto it : mp) {
			if(it.second < cur) {
				mp[it.first]++;
			}
		}
		mp[x] = 1;
	}
}