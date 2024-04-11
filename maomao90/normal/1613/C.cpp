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
ll h;
ll a[MAXN];

bool isPos(ll x) {
	ll res = 0;
	REP (i, 0, n) {
		ll mn = min(a[i + 1] - a[i], x);
		res += mn;
	}
	return res >= h;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%lld", &n, &h);
		REP (i, 0, n) {
			scanf("%lld", &a[i]);
		}
		a[n] = LINF * 3ll;
		ll lo = 1, hi = LINF, mid;
		while (lo < hi) {
			mid = lo + hi >> 1;
			if (isPos(mid)) {
				hi = mid;
			} else {
				lo = mid + 1;
			}
		}
		printf("%lld\n", hi);
	}
	return 0;
}