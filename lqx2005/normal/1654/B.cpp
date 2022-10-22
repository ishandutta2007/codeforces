#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define x first
#define y second
typedef long long ll;
typedef unsigned long long ull;
void solve() {
	string s;
	cin >> s;
	int n = s.length();
	vector<int> cnt(26);
	for(int i = n - 1; i >= 0; i--) {
		cnt[s[i] - 'a']++;
	}
	for(int i = 0; i < n; i++) {
		cnt[s[i] - 'a']--;
		if(cnt[s[i] - 'a'] == 0) {
			for(int j = i; j < n; j++) cout << s[j];
			cout << endl;
			return;
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	for(cin >> t; t--; ) {
		solve();
	}
    return 0;
}