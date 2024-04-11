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

#define INF 2000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 300005

int t;
int n;
int a[MAXN];
int isp[MAXN];

int main() {
	scanf("%d", &t);
	REP (i, 2, MAXN) {
		isp[i] = i;
	}
	REP (i, 2, MAXN) {
		if (isp[i] == i) {
			for (ll j = (ll) i * i; j < MAXN; j += i) {
				mnto(isp[j], i);
			}
		}
	}
	while (t--) {
		scanf("%d", &n);
		ll cur = 1;
		bool pos = 1;
		REP (i, 1, n + 1) {
			scanf("%d", &a[i]);
debug(" %d %d\n", i, a[i]);
			if (cur < INF) {
				cur = cur / __gcd(cur, (ll) i + 1) * (i + 1);
			}
			debug(" %d: %d %lld\n", i, a[i], cur);
			if (a[i] % cur == 0) {
				pos = 0;
			}
		}
		if (pos) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}