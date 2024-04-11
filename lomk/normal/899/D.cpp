/*input
49
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define N
#define int long long
#define bit(x,y) ((x>>y)&1LL)
#define na(x) (#x) << ":" << x
ostream& operator << (ostream &os, vector<int>&x) {
	for (int i = 0; i < x.size(); i++) os << x[i] << sp;
	return os;
}
ostream& operator << (ostream &os, pair<int, int> x) {
	cout << x.fi << sp << x.se << sp;
	return os;
}
ostream& operator << (ostream &os, vector<pair<int, int> >&x) {
	for (int i = 0; i < x.size(); i++) os << x[i] << endl;
	return os;
}
int lim = 0;
int n;

void EZ() {
	int mx = n;
	int mn = max(1LL, lim - n);
	cout << (mx - mn + 1) / 2 << endl;
}

void Hard() {
	if (lim == 0) {
		cout << n*(n - 1) / 2 << endl;
		exit(0);
	}
	int cnt = 0;
	while (n > lim + 1) {
		n -= lim + 1;
		cnt++;
	}
	int mx = n;
	int mn = max(0LL, lim - n);
	int ans = max(0LL, (mx - mn + 1) / 2);
	ans += (n + 1) * (cnt);
	if (n == lim) ans--;
	ans -= cnt;
	cnt--;
	for (int i = cnt; i >= 0; i--) {
		ans += (lim + 1) * (i) + (lim + 1) / 2;
	}
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	int len = log10(n) + 1;
	for (int i = 1; i <= len; i++) {
		lim *= 10; lim += 9;
	}
	if (n + (n - 1) >= lim) {
		EZ();
		exit(0);
	}
	lim /= 10;
	Hard();
}