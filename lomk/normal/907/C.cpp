/*input
5
! abc
. ad
. b
! cd
? c
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define int long long
#define N
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

int mask = (1 << 26) - 1;
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	bool done = false;
	int ans = 0;
	for (int j = 1; j <= q - 1; j++) {
		char c; cin >> c;
		string s; cin >> s;
		if (c == '.') {
			for (int i = 0; i < s.size(); i++) {
				int c = s[i] - 'a';
				if (bit(mask, c)) mask ^= (1 << c);
			}
		}
		else if (c == '!') {
			if (done) ans++;
			int onlymask = 0;
			for (int i = 0; i < s.size(); i++) {
				int c = s[i] - 'a';
				onlymask |= (1 << c);
			}
			mask &= onlymask;
		}
		else {
			if (done && j != q) ans++;
			int c = s[0] - 'a';
			if (bit(mask, c)) mask ^= (1 << c);
		}
		if (__builtin_popcount(mask) == 1) {
			done = true;
		}
	}
	cout << ans << endl;
}