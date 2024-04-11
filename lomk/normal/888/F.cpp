/*input

4
0 1 1 1
1 0 1 1
1 1 0 1
1 1 1 0


3
0 0 1
0 0 1
1 1 0

*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define __builtin_popcount __builtin_popcountll
#define bit(x,y) ((x>>y)&1LL)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
const int N = 505;
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

int dp[N][N][2];
int can[N][N];
int n;
const int mod = 1e9 + 7;

int cal(int l, int r, bool con) {
	l %= n; r %= n;
	int &ret = dp[l][r][con];
	if (ret != -1) return ret;
	ret = 0;
	if (l > r) r += n;
	if (l == r) return ret = 1;
	if (r - l == 1) {
		if (con) return ret = 1;
		return ret = can[l % n][r % n];
	}
	if (!con) {
		loop(i, l + 1, r) {
			if (!can[l % n][i % n]) continue;
			(ret += 1LL * cal(l, i, 1) * cal(i, r, 0) % mod) %= mod;
		}
	}
	else {
		loop(i, l, r - 1) {
			(ret += 1LL * cal(l, i, 0) * cal(i + 1, r, 0) % mod) %= mod;
		}
	}
	return ret;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	loop(i, 0, n - 1) {
		loop(j, 0, n - 1) cin >> can[i][j];
	}
	memset(dp, -1, sizeof(dp));
	// cout << cal(2, 0, 0) << endl;
	// exit(0);
	// cout << cal(1, 3, 1) << endl;
	// exit(0);
	int ans = 0;
	loop(i, 1, n - 1) {
		if (!can[0][i]) continue;
		(ans += 1LL * cal(0, i, 1) * cal(i, n - 1, 0) % mod) %= mod;
	}
	cout << ans << endl;
}