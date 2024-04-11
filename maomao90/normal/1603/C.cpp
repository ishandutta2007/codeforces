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
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#ifdef DEBUG
#define debug(args...) printf(args)
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 998244353
#define MAXN 100005

struct thing {
	int x; 
	bool pm;
   	int d, contri;
};

int t;
int n;
int a[MAXN];
vector<thing> divs[2];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 0, n) {
			scanf("%d", &a[i]);
		}
		REP (i, 0, 2) {
			divs[i].clear();
		}
		ll ans = 0;
		divs[n - 1 & 1].pb({a[n - 1], 0, 1, 1});
		RREP (i, n - 2, 0) {
			divs[i & 1].clear();
			int j;
			for (j = 1; j * j <= a[i]; j++) {
				divs[i & 1].pb({a[i] / j, a[i] % j != 0, j, 0});
			}
			j--;
			if (j * j == a[i]) j--;
			for (; j >= 1; j--) {
				if (divs[i & 1].back().x + divs[i & 1].back().pm > j + 1) {
					divs[i & 1].pb({j, 1, a[i] / (j + 1) + 1, 0});
				}
				if (a[i] % j == 0) {
					divs[i & 1].pb({j, 0, a[i] / j, 0});
				}
			}
			divs[i & 1][0].contri++;
			int ptr = 0;
			debug("%d %d\n", i, a[i]);
			for (thing &t : divs[i & 1]) {
				while (ptr < divs[i + 1 & 1].size() &&
						t.x + t.pm <= divs[i + 1 & 1][ptr].x) {
					t.contri += divs[i + 1 & 1][ptr].contri;
					t.contri %= MOD;
					ptr++;
				}
				debug(" %d %d %d %d\n", t.x, t.pm, t.d, t.contri);
				ans += (ll) t.contri * (t.d - 1) % MOD * (i + 1) % MOD;
				ans %= MOD;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}