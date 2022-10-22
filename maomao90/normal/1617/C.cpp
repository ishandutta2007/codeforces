// time-limit: 1000
// problem-url: https://codeforces.com/contest/1617/problem/C

// She will give birth to a son, and you are to give him the name Jesus,
// because he will save his people from their sins.
// Matthew 1:21
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

int n;
int occ[MAXN];
int ev[MAXN];

int main() {
	int _t = 1;
   	scanf("%d", &_t);
	while (_t--) {
		scanf("%d", &n);
		REP (i, 1, 2 * n + 1) {
			occ[i] = 0;
			ev[i] = 0;
		}
		int ans = 0;
		REP (i, 0, n) {
			int a; scanf("%d", &a);
			if (a <= n * 2) {
				occ[a]++;
			} else {
				ans++;
			}
		}
		int rem = 0;
		REP (i, 1, 2 * n + 1) {
			rem += ev[i];
			if (occ[i] == 0) {
				ev[i * 2 + 1]++;
			}
			while (occ[i] > (i <= n)) {
				if (rem <= 0) {
					ans = -1;
					break;
				}
				occ[i]--;
				rem--;
				ans++;
			}
			if (ans == -1) {
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}