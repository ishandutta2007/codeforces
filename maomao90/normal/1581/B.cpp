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
ll n, m, k;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%lld%lld%lld", &n, &m, &k);
		if (m < n - 1 || m > n * (n - 1) / 2) {
			printf("NO\n");
			continue;
		}
		if (n == 1 && m == 0) {
			if (0 < k - 1) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		} else if (m == n * (n - 1) / 2) {
			if (1 < k - 1) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		} else {
			if (2 < k - 1) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	}
	return 0;
}