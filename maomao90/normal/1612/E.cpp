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
#define MAX 51

int n;
vi mp[MAXN];
ld ans;
vi vans;

int main() {
	scanf("%d", &n);
	REP (i, 0, n) {
		int m, k; scanf("%d%d", &m, &k);
		mp[m].pb(k);
	}
	REP (i, 1, MAX) {
		vector<pair<ld, int>> v;
		REP (j, 1, MAXN) {
			if (mp[j].size() == 0) continue;
			ld cur = 0;
			for (int k : mp[j]) {
				// (i - 1 choose k - 1) / (i choose k) = k / i
				if (i <= k) {
					cur++;
				} else {
					cur += (ld) k / i;
				}
			}
			v.pb(MP(cur, j));
		}
		sort(ALL(v));
		reverse(ALL(v));
		if (v.size() < i) continue;
		vi tv;
		ld prob = 0;
		REP (j, 0, i) {
			tv.pb(v[j].SE);
			prob += v[j].FI;
		}
		debug("%d: %Lf\n", i, prob);
		if (mxto(ans, prob)) {
			vans = tv;
		}
	}
	printf("%d\n", (int) vans.size());
	for (int i : vans) {
		printf("%d ", i);
	}
	printf("\n");
	return 0;
}