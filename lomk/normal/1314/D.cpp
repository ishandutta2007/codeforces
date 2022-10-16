/*input
3 2
0 1 1
2 0 1
2 2 0
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
const int N = 85, INF = 2e9;
int n, len, a[N][N], ans = INF;
vector<pair<int, int> > d1[N][N];
vector<int> path;
bitset<N> cnt;

void updateAns() {
	path.push_back(0);
	for (auto it : path) cnt[it] = 1;
	int ret = 0;
	loop(i, 1, path.size() - 1) {
		int u = path[i - 1]; int v = path[i]; bool ok = false;
		for (auto &it : d1[u][v]) {
			if (cnt[it.se]) continue;
			ret += it.fi; ok = true; break;
		}
		if (!ok) goto done;
	}
	ans = min(ans, ret);
done:
	for (auto it : path) cnt[it] = 0;
	path.pop_back();
	return;
}

void solve() {
	path = {0};
	if (len == 2) updateAns();
	else if (len == 4) {
		loop(u1, 0, n - 1) {
			path.push_back(u1);
			updateAns();
			path.pop_back();
		}
	} else if (len == 6) {
		loop(u1, 0, n - 1) {
			path.push_back(u1);
			loop(u2, 0, n - 1) {
				path.push_back(u2);
				updateAns();
				path.pop_back();
			}
			path.pop_back();
		}
	}
	else if (len == 8) {
		loop(u1, 0, n - 1) {
			path.push_back(u1);
			loop(u2, 0, n - 1) {
				path.push_back(u2);
				loop(u3, 0, n - 1) {
					path.push_back(u3);
					updateAns();
					path.pop_back();
				}
				path.pop_back();
			}
			path.pop_back();
		}
	} else if (len == 10) {
		loop(u1, 0, n - 1) {
			path.push_back(u1);
			loop(u2, 0, n - 1) {
				path.push_back(u2);
				loop(u3, 0, n - 1) {
					path.push_back(u3);
					loop(u4, 0, n - 1) {
						path.push_back(u4);
						updateAns();
						path.pop_back();
					}
					path.pop_back();
				}
				path.pop_back();
			}
			path.pop_back();
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> len;
	loop(i, 0, n - 1) {
		loop(j, 0, n - 1) cin >> a[i][j];
	}
	loop(i, 0, n - 1) {
		loop(j, 0, n - 1) {
			loop(k, 0, n - 1) {
				if (k != i && k != j)
					d1[i][j].push_back({a[i][k] + a[k][j], k});
			}
			sort(d1[i][j].begin(), d1[i][j].end());
		}
	}
	solve();
	cout << ans << endl;
}