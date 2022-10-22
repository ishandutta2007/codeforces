// time-limit: 1000
// problem-url: https://codeforces.com/contest/1616/problem/C

// he refreshes my soul. He guides me along the right
// paths for his name's sake
// Psalms 23:3
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
#define MAXN 75

int t;
int n;
int a[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 0, n) {
			scanf("%d", &a[i]);
		}
		if (n <= 2) {
			printf("0\n");
			continue;
		}
		int ans = n - 1;
		REP (i, 0, n) {
			REP (j, i + 1, n) {
				int d = a[j] - a[i];
				int res = 0;
				REP (k, 0, n) {
					if (k == i || k == j) {
						continue;
					}
					// d / (j - i) * (k - i) + a[i]
					if (d * (k - i) % (j - i) != 0) {
						res++;
					} else if (d * (k - i) / (j - i) + a[i] != a[k]) {
						res++;
					}
				}
				mnto(ans, res);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}