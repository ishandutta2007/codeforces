// time-limit: 2000
// problem-url: https://codeforces.com/contest/1622/problem/C

// Dear friends, since God so loved us, we also ought to love one another
// 1 John 4:11
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
ll k;
int a[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%lld", &n, &k);
		ll sm = 0;
		REP (i, 0, n) {
			scanf("%d", &a[i]);
			sm += a[i];
		}
		if (sm <= k) {
			printf("0\n");
			continue;
		}
		sort(a, a + n);
		ll ans = sm - k;
		RREP (i, n - 1, 1) {
			sm -= a[i] - a[0];
			ll d = sm - k;
			if (d <= 0) {
				mnto(ans, (ll) n - i);
			} else {
				mnto(ans, n - i + max(0ll, (d - 1) / (n - i + 1) + 1));
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}