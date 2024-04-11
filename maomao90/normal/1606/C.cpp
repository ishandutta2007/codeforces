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
#define LINF 9000000000000000005
#define MOD 1000000007
#define MAXN 15

int t;
int n, k;
ll pw[20];
int a[MAXN];

ll cost(ll x) {
	ll res = 0;
	RREP (i, n - 1, 0) {
		res += x / pw[a[i]];
		x %= pw[a[i]];
	}
	return res;
}

int main() {
	scanf("%d", &t);
	pw[0] = 1;
	REP (i, 1, 19) {
		pw[i] = pw[i - 1] * 10;
	}
	while (t--) {
		scanf("%d%d", &n, &k);
		REP (i, 0, n) {
			scanf("%d", &a[i]);
		}
		ll ans = 0;
		RREP (i, 18, 0) {
			REP (j, 0, 10) {
				ans += pw[i];
				ans--;
				if (cost(ans) > k) {
					ans++;
					ans -= pw[i];
					break;
				} else {
					ans++;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}