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
#define MAXN 300005

int t;
int a, b;
int x[MAXN];

int main() {
	scanf("%d", &t);
	REP (i, 1, MAXN) {
		x[i] = x[i - 1] ^ i;
	}
	while (t--) {
		scanf("%d%d", &a, &b);
		int cx = x[a - 1];
		int ans = 0;
		if (cx == b) {
			ans = 0;
		} else if ((cx ^ b) == a) {
			ans = 2;
		} else {
			ans = 1;
		}
		ans += a;
		printf("%d\n", ans);
	}
	return 0;
}