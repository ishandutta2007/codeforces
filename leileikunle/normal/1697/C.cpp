#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define int long long
const int N = 70 + 10, M = N * N;
int n;
string s, t;
void solve() {

	cin >> n >> s >> t;
	s = " " + s, t = " " + t;
	vector<int> a, b;
	string s1, s2;
	for (int i = 1; i <= n; i++) {
		if (s[i] != 'b') s1 += s[i], a.push_back(i);
		if (t[i] != 'b') s2 += t[i], b.push_back(i);
	}
	if (s1 != s2) return void(cout << "NO\n");
	int sz = a.size(), flag(0);
	for (int i = 0; i < sz; i++) {
		if (s1[i] == 'a' and a[i] > b[i]) flag = 1;
		if (s1[i] == 'c' and a[i] < b[i]) flag = 1;
	}
	cout << (flag == 1 ?  "NO\n" : "YES\n");

}
signed main() {

	cin.tie(0) -> ios::sync_with_stdio(false);
	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}