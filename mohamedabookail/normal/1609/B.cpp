/**
*    author:  Mohamed Abo Okail
*    created: 28/11/2O21
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
 
	int n, q; cin >> n >> q;
	string s; cin >> s;
	int cnt = 0;
	for (int i = 2; i < n; i++) {
		if(s[i] == 'c' && s[i - 1] == 'b' && s[i - 2] == 'a') {
			cnt++;
		}
	}
	while(q--) {
		int x; cin >> x;
		char ch; cin >> ch;
		int cntt = 0, cntt2 = 0;
		for (int i = max(x - 5, 2); i < min(x + 10, n); i++) {
			if(s[i] == 'c' && s[i - 1] == 'b' && s[i - 2] == 'a') {
				cntt++;
			}
		}
		s[x - 1] = ch;
		for (int i = max(x - 5, 2); i < min(x + 10, n); i++) {
			if(s[i] == 'c' && s[i - 1] == 'b' && s[i - 2] == 'a') {
				cntt2++;
			}
		}
		cnt += (cntt2 - cntt);
		cout << cnt << endl;
	}
}