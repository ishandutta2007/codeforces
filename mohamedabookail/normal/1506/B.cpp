/**
*    author:  Mohamed Abo Okail
*    created: 2O/O5/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n"

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;
		string s; cin >> s;
		int ans = 0;
		k--;
		for (int i = 0; i < n; i++) {
			if(s[i] == '*') {
				s[i] = 'x';
				ans++;
				break;
			}
		}
		for (int i = n - 1; i >= 0 ; i--) {
			if(s[i] == '*') {
				s[i] = 'x';
				ans++;
				break;
			}
		}
		for (int i = 0; i < n; i++) {
			if(s[i] == 'x') {
				if(i + k + 1 >= n - 1) break;
				for (int j = i + k + 1; j >= 0; j--) {
					if(s[j] == 'x') {
						i = n;
						break;
					}
					if(s[j] == '*') {
						s[j] = 'x';
						ans++;
						i = j - 1;
						break;
					}
				}
			}
		}

		cout << ans << endl;
	}
}