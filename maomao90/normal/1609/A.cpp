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
ll a[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		ll pw = 1;
		REP (i, 0, n) {
			scanf("%lld", &a[i]);
			while (a[i] % 2 == 0) {
				a[i] /= 2;
				pw *= 2;
			}
		}
		sort(a, a + n);
		a[n - 1] *= pw;
		ll ans = 0;
		REP (i, 0, n) {
			ans += a[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}