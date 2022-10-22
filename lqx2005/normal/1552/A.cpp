#include <bits/stdc++.h>
using namespace std;
int n;

void solve() {
	cin >> n;
	string s;
	cin >> s;
	string t = s;
	sort(t.begin(), t.end());
	int cnt = 0;
	for(int i = 0; i < n; i++) if(s[i] != t[i]) cnt++;
	cout << cnt << endl;
	return;
}

int main() {
	int T;
	for(cin >> T;T-- ; ) {
		solve();
	}
    return 0;
}