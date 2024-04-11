// time-limit: 1000
// problem-url: https://codeforces.com/contest/1591/problem/C
// Be kind and compassionate to one another, forgiving each other,
// just as in Christ God forgave you. Ephesians 4:32
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

int n, k;
int x[MAXN];
int nn;
int nx[MAXN];

int main() {
	int _t = 1;
   	scanf("%d", &_t);
	while (_t--) {
		scanf("%d%d", &n, &k);
		REP (i, 0, n) {
			scanf("%d", &x[i]);
		}
		sort(x, x + n);
		nn = n;
		REP (i, 0, n) {
			if (x[i] >= 0) {
				nn = i;
				break;
			}
			nx[i] = -x[i];
		}
		reverse(nx, nx + nn);
		ll ans = 0;
		int mn = INF;
		for (int i = nn - k - 1; i >= 0; i -= k) {
			debug(" %d\n", nx[i]);
			ans += nx[i] * 2;
		}
		if (nn > 0) {
			debug(" %d\n", nx[nn - 1]);
			ans += nx[nn - 1];
			mnto(mn, nx[nn - 1]);
		} else {
			mn = 0;
		}
		for (int i = n - k - 1; i >= nn; i -= k) {
			debug(" +%d\n", x[i]);
			ans += x[i] * 2;
		}
		if (n - 1 >= nn) {
			ans += x[n - 1];
			mnto(mn, x[n - 1]);
		} else {
			mn = 0;
		}
		ans += mn;
		printf("%lld\n", ans);
	}
	return 0;
}