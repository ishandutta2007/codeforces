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
ii ab[MAXN];
int occ[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 1, n + 1) {
			occ[i] = 0;
		}
		REP (i, 0, n) {
			scanf("%d%d", &ab[i].FI, &ab[i].SE);
			occ[ab[i].SE]++;
		}
		sort(ab, ab + n);
		int l = 0, r = 0;
		ll ans = 0;
		while (l < n) {
			int a = ab[l].FI;
			for (; r < n && ab[r].FI == a; r++) {}
			for (int i = l; i < n && ab[i].FI == a; i++) {
				debug("%d %d: %d\n", ab[i].FI, ab[i].SE, occ[ab[i].SE] - 1);
				ans += (ll) (r - l - 1) * (occ[ab[i].SE] - 1);
			}
			l = r;
		}
		ans = (ll) n * (n - 1) * (n - 2) / 6 - ans;
		printf("%lld\n", ans);
	}
	return 0;
}