// time-limit: 1000
// problem-url: https://codeforces.com/contest/1616/problem/A

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
#define MAXN 105

int t;
int n;
int a[MAXN];
int cnt[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(cnt, 0, sizeof cnt);
		int ans = 0;
		REP (i, 0, n) {
			scanf("%d", &a[i]);
			if (a[i] == 0) {
				ans = 1;
			   	continue;
			}
			cnt[abs(a[i])]++;
		}
		REP (i, 0, MAXN) {
			if (cnt[i] == 1) {
				ans++;
			} else if (cnt[i] >= 2) {
				ans += 2;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}