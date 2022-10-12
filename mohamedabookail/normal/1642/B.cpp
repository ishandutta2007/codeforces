/**
*    author:  Mohamed Abo Okail
*    created: 23/O2/2O22
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n";
 
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector < ll > a(n), ans;
		map < ll , ll > mp;
		ll x, cur = n;
		for (int i = 0; i < n; i++) {
			cin >> x;
			mp[x]++;
		}
		for(auto it : mp) {
			a.push_back(it.second);
		}
		sort(all(a));
		reverse(all(a));
		ans.push_back(cur);
		for (int i = 0; i < sz(a); i++) {
			if(a[i] > 1) {
				a[i]--;
				cur--;
				ans.push_back(cur);
				i--;
			}
			if(sz(ans) == n) {
				break;
			}
		}
		while(sz(ans) < n) {
			ans.push_back(ans.back());
		}
		reverse(all(ans));
		for (int i = 0; i < n; i++) {
			cout << ans[i] << ' ';
		}
		cout << endl;
	}
}