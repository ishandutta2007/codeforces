#include <bits/stdc++.h> 
using namespace std;

template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define MT make_tuple
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb emplace_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 100005
#define BLK 320

#ifdef DEBUG
#define debug(args...) _debug(__LINE__, args)
void _debug(int line, const char* format, ...) {
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}
#else
#define debug(args...)
#endif

int n, m, q;
ll a[MAXN];
int w[MAXN], inv[BLK + 5], id[MAXN], cnt[BLK + 5][MAXN], ptr, inter[MAXN][BLK + 5];
vi b[MAXN];
ll lazy[MAXN], sum[MAXN];

int main() {
	scanf("%d%d%d", &n, &m, &q);
	REP (i, 1, n + 1) {
		scanf("%lld", &a[i]);
	}
	REP (i, 1, m + 1) {
		scanf("%d", &w[i]);
		b[i].resize(w[i]);
		REP (j, 0, w[i]) {
			scanf("%d", &b[i][j]);
		}
		if (w[i] > BLK) {
			inv[ptr] = i;
			id[i] = ptr++;
			for (auto &j : b[i]) {
				cnt[id[i]][j] = 1;
			}
		}
	}
	REP (i, 1, m + 1) {
		REP (j, 0, ptr) {
			for (auto &k : b[i]) {
				//debug(" %d %d: %d\n", j, k, cnt[j][k]);
				inter[i][j] += cnt[j][k];
			}
			debug("%d %d: %d\n", i, j, inter[i][j]);
		}
	}
	REP (i, 1, m + 1) {
		for (auto &k : b[i]) {
			sum[i] += a[k];
		}
	}
	while (q--) {
		char c; int i; scanf(" %c%d", &c, &i);
		if (c == '?') {
			ll res = 0;
			if (w[i] <= BLK) {
				for (auto &k : b[i]) {
					res += a[k];
				}
				REP (j, 0, ptr) {
					res += (ll) lazy[j] * inter[i][j];
				}
			} else {
				res = sum[i];
				REP (j, 0, ptr) {
					res += (ll) lazy[j] * inter[i][j];
					debug(" %d: %d %d\n", j, lazy[j], inter[i][j]);
				}
			}
			printf("%lld\n", res);
		} else {
			int x; scanf("%d", &x);
			if (w[i] <= BLK) {
				for (auto &k : b[i]) {
					a[k] += x;
				}
				REP (j, 0, ptr) {
					sum[inv[j]] += (ll) inter[i][j] * x;
				}
			} else {
				lazy[id[i]] += x;
			}
		}
	}
	return 0;
}