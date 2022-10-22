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
#define MOD 998244353
#define MAXN 500015

int t;
int n;
int a[MAXN];
ll dp1[MAXN], dp2[MAXN], psm1[MAXN], psm2[MAXN];
int lst[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 0, n) {
			scanf("%d", &a[i]);
			a[i] += 2;
		}
		REP (i, 0, n + 10) {
			dp1[i] = dp2[i] = psm1[i] = psm2[i] = 0;
			lst[i] = -1;
		}
		psm1[1] = 1;
		ll ans = 0;
		REP (i, 0, n) {
			dp1[i] = (psm1[a[i]] + psm1[a[i] - 1]) % MOD;
			dp2[a[i]] = (psm2[a[i]] + psm1[a[i] - 2]) % MOD;
			dp2[a[i] + 2] = psm2[a[i] + 2];
			ans = (ans + dp1[i] + dp2[a[i]] + dp2[a[i] + 2]) % MOD;
			psm1[a[i]] = (psm1[a[i]] + dp1[i]) % MOD;
			psm2[a[i]] = (psm2[a[i]] + dp2[a[i]]) % MOD;
			psm2[a[i] + 2] = (psm2[a[i] + 2] + dp2[a[i] + 2]) % MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}