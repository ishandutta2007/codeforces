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

#ifdef DEBUG
#define debug(args...) _debug(args)
void _debug(const char* format, ...) {
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 2000005

ll n, k, x;
ll a[MAXN];
priority_queue<ll, vll, greater<ll>> pq;

int main() {
	scanf("%lld%lld%lld", &n, &k, &x);
	REP (i, 1, n + 1) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	REP (i, 1, n) {
		ll diff = a[i + 1] - a[i] - 1;
		ll res = max(diff / x, 0ll);
		debug(" %lld %lld\n", diff, res);
		pq.push(res);
	}
	int ans = n;
	while (!pq.empty()) {
		ll tp = pq.top(); pq.pop();
		if (k >= tp) {
			k -= tp;
			ans--;
		}
	}
	printf("%d\n", ans);
}