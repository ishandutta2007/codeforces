/**
*    author:  Mohamed Abo Okail
*    created: 29/O3/2O21
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

	int t; cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector < int > a;
		map < int, int > mp;
		for (int i = 0; i < n; i++) {
			int oo; cin >> oo;
			mp[oo]++;
			if(mp[oo] == 1) {
				a.push_back(oo);
			}
		}
		sort(all(a));
		for (int i = 0; i < sz(a); i++) {
			cout << a[i] << ' ';
		}
		for(auto it : mp) {
			while(mp[it.first]-- > 1) {
				cout << it.first << ' ';
			}
		}
		cout << endl;
	}
}