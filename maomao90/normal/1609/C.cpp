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
#define MAX 1000005

int t;
int n, e;
int a[MAXN];
int lft[MAXN], rht[MAXN];
bool isp[MAX];

int main() {
	scanf("%d", &t);
	REP (i, 2, MAX) {
		isp[i] = 1;
	}
	for (int i = 2; i * i < MAX; i++) {
		if (!isp[i]) continue;
		for (int j = i * 2; j < MAX; j += i) {
			isp[j] = 0;
		}
	}
	while (t--) {
		scanf("%d%d", &n, &e);
		REP (i, 0, n) {
			scanf("%d", &a[i]);
		}
		REP (i, 0, e) {
			lft[i] = i;
			for (int j = i + e; j < n; j += e) {
				if (a[j - e] == 1) {
					lft[j] = lft[j - e];
				} else {
					lft[j] = j;
				}
			}
			rht[n - 1 - i] = n - 1 - i;
			for (int j = n - 1 - i - e; j >= 0; j -= e) {
				if (a[j + e] == 1) {
					rht[j] = rht[j + e];
				} else {
					rht[j] = j;
				}
			}
		}
		ll ans = 0;
		REP (i, 0, n) {
			if (!isp[a[i]]) continue;
			ll r = (rht[i] - i) / e + 1, l = (i - lft[i]) / e + 1;
			ans += r * l - 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}