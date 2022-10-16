/*input
6
0 1 2 3 3 5
3
1 2
1 4
3 6


8
8 7 3 1 7 0 9 4
3
1 8
2 5
7 7
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define mp make_pair
#define fi first
#define se second
#define __builtin_popcount __builtin_popcountll
#define int long long
#define loop(i,l,r) for(int i=(l); i<=(r); i++)
#define rloop(i,l,r) for(int i=(l); i>=(r); i--)
#define bit(x,y) ((x>>y)&1LL)
const int N = 1e5 + 5;
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
	return os << '(' << a.first << ", " << a.second << ')';
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
	os << '[';
	for (unsigned int i = 0; i < a.size(); i++)
		os << a[i] << (i < a.size() - 1 ? ", " : "");
	os << ']';
	return os;
}

int n;
vector<int> a;
pair<int, int> dp[N][22]; // candy, get
int lg2[N];

pair<int, int> comb(pair<int, int> X, pair<int, int> Y) {
	pair<int, int> ret;
	ret.fi = X.fi + Y.fi;
	ret.se = (X.se + Y.se) % 10;
	if (X.se + Y.se >= 10) ret.fi++;
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	lg2[1] = 0;
	loop(i, 2, N - 5) lg2[i] = lg2[i / 2] + 1;
	cin >> n;
	loop(i, 1, n) {
		int t; cin >> t;
		a.push_back(t);
	}
	for (int k = 0; k <= 20; k++) {
		if (k == 0) {
			for (int i = 0; i < n; i++) dp[i][k] = mp(0, a[i]);
		} else {
			for (int i = 0; i + (1 << k) - 1 < n; i++) {
				dp[i][k] = comb(dp[i][k - 1], dp[i + (1 << (k - 1))][k - 1]);
			}
		}
	}
	int q; cin >> q;
	loop(Q, 1, q) {
		int l, r; cin >> l >> r;
		l--; r--;
		int p = lg2[r - l + 1];
		cout << dp[l][p].fi << endl;
	}
}