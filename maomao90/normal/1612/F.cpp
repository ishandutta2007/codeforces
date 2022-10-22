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

int n, m;
int q;
set<ii> syn;
int dp[MAXN];

int main() {
	scanf("%d%d", &n, &m);
	scanf("%d",  &q);
	while (q--) {
		int a, b; scanf("%d%d", &a, &b);
		if (n > m) swap(a, b);
		syn.insert(MP(a, b));
	}
	if (n > m) {
		swap(n, m);
	}
	REP (i, 0, n + 1) {
		dp[i] = -INF;
	}
	dp[1] = 1;
	int ans = 0;
	while (++ans) {
		RREP (i, n, 1) {
			if (dp[i] == -INF) {
				continue;
			}
			int s = i + dp[i];
			if (syn.find(MP(i, dp[i])) != syn.end()) {
				s++;
			}
			mxto(dp[min(n, s)], dp[i]);
			mxto(dp[i], min(m, s));
		}
		/*
		REP (i, 1, n + 1) {
			debug("%d: %d\n", i, dp[i]);
		}
		*/
		if (dp[n] == m) {
			printf("%d\n", ans);
			return 0;
		}
	}
	assert(0);
	return 0;
}