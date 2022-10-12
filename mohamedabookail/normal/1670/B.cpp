/**
*    author:  Mohamed Abo Okail
*    created: O9/O5/2O22
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
		int n;
		cin >> n;
		string s; cin >> s;
		int k;
		cin >> k;
		map < char , int > mp;
		for (int i = 0; i < k; i++) {
			char ch;
			cin >> ch;
			mp[ch]++;
		}
		ll ans = 0, cnt = 0, flag = 0;
		for (int i = 0; i < n; i++) {
			if(mp[s[i]]) {
				if(cnt >= ans) {
					ans = cnt;
					flag++;
				}
				cnt = 0;
			}
			else {
				cnt++;
			}
		}
		cout << ans + (flag > 1) << endl;
	}
}