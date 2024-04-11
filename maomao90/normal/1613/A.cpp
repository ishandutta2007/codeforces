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
ll x1, p1, x2, p2;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%lld%lld%lld%lld", &x1, &p1, &x2, &p2);
		int mn = min(p1, p2);
		p1 -= mn, p2 -= mn;
		if (max(p1, p2) >= 10) {
			if (p1 > 0) {
				printf(">\n");
			} else {
				printf("<\n");
			}
			continue;
		}
		if (p1 > 0) {
			REP (i, 0, p1){ 
				x1 *= 10;
			}
		} else {
			REP (i, 0, p2) {
				x2 *= 10;
			}
		}
		if (x1 > x2) {
			printf(">\n");
		} else if (x1 == x2) {
			printf("=\n");
		} else {
			printf("<\n");
		}
	}
	return 0;
}