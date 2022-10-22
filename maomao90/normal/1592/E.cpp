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
#define MAXN 1050005

int n;
int a[MAXN];
int p[MAXN];
vi occ[2][MAXN];
int ans;

int main() {
	scanf("%d", &n);
	REP (i, 1, n + 1) {
		scanf("%d", &a[i]);
	}
	RREP (k, 20, 0) {
		REP (i, 1, n + 1) {
			p[i] = a[i] >> k;
			p[i] ^= p[i - 1];
			debug("%d: %d\n", i, p[i]);
		}
		int l = 1;
		occ[0][0].pb(0);
		REP (r, 1, n + 1) {
			if (!(a[r] & (1 << k))) {
				l = r;
			} else {
				while (!(a[l] & (1 << k))) {
					l++;
				}
				auto it = lower_bound(ALL(occ[r & 1][p[r]]), l - 1);
				if (it != occ[r & 1][p[r]].end()) {
					mxto(ans, r - *it);
				}
			}
			occ[r & 1][p[r]].pb(r);
		}
		occ[0][0].clear();
		REP (i, 1, n + 1) {
			occ[i & 1][p[i]].clear();
		}
	}
	printf("%d\n", ans);
	return 0;
}