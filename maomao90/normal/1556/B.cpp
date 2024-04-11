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
#define MOD 1000000007
#define MAXN 200005

int t;
int n;
int a[MAXN], ta[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		vi v[5];
		v[0].clear();
		v[1].clear();
		REP (i, 0, n) {
			scanf("%d", &a[i]);
			a[i] %= 2;
			ta[i] = a[i];
			v[a[i]].pb(i);
		}
		ll ans = LINF;
		REP (k, 0, 2) {
			int cnt[] = {0, 0};
			REP (i, 0, n) {
				ta[i] = a[i];
				if (ta[i] != (i + k) % 2) {
					cnt[i & 1]++;
				}
			}
			if (cnt[0] != cnt[1]) {
				continue;
			}
			REP (i, 0, n) {
				debug(" %d", ta[i]);
			}
			debug("\n");
			int ptr[2] = {0, 0};
			ll res = 0;
			REP (i, 0, n) {
				REP (j, 0, 2) {
					if (ptr[j] < v[j].size() && v[j][ptr[j]] == i) ptr[j]++;
				}
				if (ta[i] != (i + k) % 2) {
					debug("  %d\n", i);
					debug("   %d %d\n", ptr[1 - ta[i]], (int) v[i - ta[i]].size());
					assert(ptr[1 - ta[i]] < v[1 - ta[i]].size());
					int j = v[1 - ta[i]][ptr[1 - ta[i]]];
					res += j - i;
					ptr[1 - ta[i]]++;
					swap(ta[i], ta[j]);
				}
			}
			mnto(ans, res);
		}
		if (ans == LINF) {
			printf("-1\n");
		} else {
			printf("%lld\n", ans);
		}
	}
	return 0;
}