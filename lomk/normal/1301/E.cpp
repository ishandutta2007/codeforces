/*input
5 5 1
RRGGB
RRGGY
YYBBG
YYBBR
RBBRG
2 2 5 5
*/
#ifdef UncleGrandpa
#include <prettyprint.hpp>
#endif
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(l); i<=(r); i++)
#define rloop(i,l,r) for(int i=(l); i>=(r); i--)
#define debug(x...) {cout << "[" << #x << "] ="; _print(x);}
void _print() {cout << endl;}
template<typename T, typename... Ts> void _print(const T& value, const Ts&... values) {cout << ' ' << value; _print(values...);}
template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value; _print(values...);}
// change cout to cerr for debug in crash
// for struct, can write print operator to use print() (even with SegTree)
const int N = 505;

int n, m, q;
char a[N][N];
int rlen[N][N], dlen[N][N];
int sum[N][N][N];

int querySum(int p, int x1, int y1, int x2, int y2) {
	return sum[p][x2][y2] - sum[p][x2][y1 - 1] - sum[p][x1 - 1][y2] + sum[p][x1 - 1][y1 - 1];
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> q;
	loop(i, 1, n) loop(j, 1, m) cin >> a[i][j];
	rloop(i, n, 1) rloop(j, m, 1) {
		if (a[i][j] == a[i][j + 1]) rlen[i][j] = rlen[i][j + 1] + 1;
		else rlen[i][j] = 1;
		if (a[i][j] == a[i + 1][j]) dlen[i][j] = dlen[i + 1][j] + 1;
		else dlen[i][j] = 1;
	}
	loop(i, 1, n) {
		loop(j, 1, m) {
			if (a[i][j] != 'R' || dlen[i][j] != rlen[i][j]) continue;
			int S = rlen[i][j]; int nxt = -1;
			if (j + 2 * S - 1 > m) continue;
			for (int k = j; k <= j + 2 * S - 1; k++) {
				bool ok = [&] {
					if (dlen[i][k] != S) return false;
					if (k - j < S) {
						if (a[i][k] != 'R' || a[i + S][k] != 'Y') return false;
					}
					else {
						if (a[i][k] != 'G' || a[i + S][k] != 'B') return false;
					}
					if (dlen[i + S][k] < S) return false;
					return true;
				}();
				if (!ok) {
					nxt = k;
					break;
				}
			}
			if (nxt != -1) {
				j = max(j, nxt - 1);
				continue;
			}
			sum[S][i][j]++;
			// print("Square", i, j, S);
			nxt = j + 2 * S - 1;
		}
	}
	loop(lev, 1, min(n, m)) {
		loop(i, 1, n) {
			loop(j, 1, m) {
				sum[lev][i][j] += sum[lev][i - 1][j] + sum[lev][i][j - 1] - sum[lev][i - 1][j - 1];
			}
		}
	}
	// cout << querySum(2, 2, 3, 2, 5) << endl;
	// exit(0);
	loop(Q, 1, q) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		int l = 1, r = min(x2 - x1 + 1, y2 - y1 + 1) / 2;
		int ans = 0;
		rloop(i, r, l) {
			int xlen = 2 * i;
			if (x2 - xlen + 1 >= x1 && y2 - xlen + 1 >= y1 && querySum(i, x1, y1, x2 - xlen + 1, y2 - xlen + 1)) {
				ans = i; break;
			}
		}
		cout << ans*ans * 4 << endl;
		// // cout << check(2) << endl;
		// // exit(0);
		// while (l != r) {
		// 	int mid = (l + r + 1) / 2;
		// 	if (check(mid)) l = mid;
		// 	else r = mid - 1;
		// }
		// if (check(l)) cout << l*l * 4 << endl;
		// else cout << 0 << endl;
	}
}