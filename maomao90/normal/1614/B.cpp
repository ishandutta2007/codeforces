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
ii a[MAXN];
int x[MAXN];
int pos[MAXN];

int main() {
	scanf("%d", &t);
	int ptr = 1;
	for (int i = 1; i < MAXN; i += 2) {
		pos[i] = ptr;
		pos[i + 1] = -ptr;
		ptr++;
	}
	while (t--) {
		scanf("%d", &n);
		REP (i, 1, n + 1) {
			scanf("%d", &a[i].FI);
			a[i].SE = i;
		}
		sort(a + 1, a + n + 1, greater<ii>());
		ll ans = 0;
		REP (i, 1, n + 1) {
			x[a[i].SE] = pos[i];
			debug("%d %d\n", a[i].FI, pos[i]);
			ans += (ll) 2 * a[i].FI * abs(pos[i]);
		}
		printf("%lld\n", ans);
		REP (i, 0, n + 1) {
			printf("%d ", x[i]);
		}
		printf("\n");
	}
	return 0;
}