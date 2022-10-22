// time-limit: 2000
// problem-url: https://codeforces.com/contest/1615/problem/C

// Glory to God in the highest heaven, and on earth peace to those
// on whom his favor rests
// Luke 2:14
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
char a[MAXN], b[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		scanf(" %s", a);
		scanf(" %s", b);
		int za = 0, oa = 0;
		REP (i, 0, n) {
			if (a[i] == '0') {
				za++;
			} else {
				oa++;
			}
		}
		int zb = 0, ob = 0;
		REP (i, 0, n) {
			if (b[i] == '0') {
				zb++;
			} else {
				ob++;
			}
		}
		int ans = INF;
		if (za == zb) {
			int cur = 0;
			REP (i, 0, n) {
				cur += a[i] != b[i];
			}
			mnto(ans, cur);
		}
		if (oa - 1 == zb) {
			int cur = 0;
			REP (i, 0, n) {
				cur += a[i] == b[i];
			}
			mnto(ans, cur);
		}
		if (ans == INF) {
			ans = -1;
		}
		printf("%d\n", ans);
	}
	return 0;
}