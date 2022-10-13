/**
*    author:  Mohamed Abo Okail
*    created: 11/O4/2O21
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
		int n, k; cin >> n >> k;
		if(k >= (n + 1) / 2) {
			cout << -1 << endl;
			continue;
		}
		vector < int > a(n), ans;
		for (int i = 0; i < n; i++) {
			a[i] = i + 1;
		}
		map < int , int > mp;
		int back = n - k + 1;
		for (int i = 0; i < n; i++) {
			if(mp[i]) break;
			ans.push_back(i + 1);
			if(k > 0) {
				ans.push_back(back);
				k--;
				mp[back]++;
				back++;
			}
		}
		for (int i = 0; i < n; i++) {
			cout << ans[i] << ' ';
		}
		cout << endl;
	}
}