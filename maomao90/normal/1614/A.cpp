// problem-url: https://codeforces.com/contest/1614/problem/A
// time-limit: 3000
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
int n, l, r, k;
int a[MAXN];
vi useful;
 
int main() {
	scanf("%d", &t);
	while (t--) {
		useful.clear();
		scanf("%d%d%d%d", &n, &l, &r, &k);
		REP (i, 0, n) {
			scanf("%d", &a[i]);
			if (l <= a[i] && a[i] <= r) {
				useful.pb(a[i]);
			}
		}
		sort(ALL(useful));
		int ans = 0;
		REP (i, 0, useful.size()) {
			if (useful[i] <= k) {
				k -= useful[i];
				ans++;
			} else {
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}