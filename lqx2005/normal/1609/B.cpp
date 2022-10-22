#include <bits/stdc++.h>
#define broken cerr << "running on " << __FUNCTION__ <<" "<< __LINE__ << endl
#define x first
#define y second
#define sz(a) int((a).size())
#define ll long long
#define ull unsigned long long
using namespace std;
const int N = 1e5 + 10;
int n, q;
char s[N];
int ok(int x) {
	if(x - 2 < 1 || x > n) return 0;
	return s[x - 2] == 'a' && s[x - 1] == 'b' && s[x] == 'c';
}
void solve() {
	cin >> n >> q;
	cin >> (s + 1);
	int cnt = 0;
	for(int i = 3; i <= n; i++) cnt += ok(i);
	for(int i = 1; i <= q; i++) {
		char x;
		int p;
		cin >> p >> x;
		cnt -= ok(p - 2) + ok(p - 1) + ok(p) + ok(p + 1) + ok(p + 2);
		s[p] = x;
		cnt += ok(p - 2) + ok(p - 1) + ok(p) + ok(p + 1) + ok(p + 2);
		cout << cnt << endl;
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solve();
	// for(cin >> t; t--; solve());
	return 0;
}