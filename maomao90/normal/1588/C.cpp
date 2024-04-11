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
#define MAXN 300005

int t;
int n;
int a[MAXN];
ll psm[2][MAXN];
int rht[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 1, n + 1) {
			scanf("%d", &a[i]);
		}
		REP (i, 1, n + 1) {
			psm[1][i] = a[i] + psm[0][i - 1];
			psm[0][i] = -a[i] + psm[1][i - 1];
		}
		REP (i, 1, n + 1) {
			rht[i] = INF;
		}
		vector<pll> v[2];
		RREP (i, n, 1) {
			bool b = i & 1;
			while (!v[b].empty() &&
					v[b].back().FI >= psm[1][i]) {
				v[b].pop_back();
			}
			v[b].pb(MP(psm[1][i], i));
			REP (j, 0, 2) {
				ll x = psm[j][i - 1];
				auto ptr = lower_bound(ALL(v[b ^ j]), pll(x, -1));
				if (ptr != v[b ^ j].begin()) {
					ptr = prev(ptr);
					mnto(rht[i], (int) ptr -> SE);
				}
			}
			debug("%d: %d\n", i, rht[i]);
		}
		map<ll, vi> mp[2];
		ll ans = 0;
		RREP (i, n, 1) {
			bool b = i & 1;
			REP (j, 0, 2) {
				mp[b ^ j][psm[1 ^ j][i]].pb(i);
				debug(" + %d %lld: %d\n", b ^ j, psm[1 ^ j][i], i);
			}
			debug("%d: %lld\n", i, psm[0][i - 1]);
			int res = mp[b][psm[0][i - 1]].end() - upper_bound(
					ALL(mp[b][psm[0][i - 1]]), rht[i], greater<int>());
			ans += res;
		}
		printf("%lld\n", ans);
	}
	return 0;
}