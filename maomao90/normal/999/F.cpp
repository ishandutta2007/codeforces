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
#define pb emplace_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAX 100005
#define MAXN 505
#define MAXK 15

int n, k;
int cnt[MAX], cntf[MAX];
int f[MAXN];
int h[MAXK];
ll dp[MAXN][MAXN * MAXK]; // dp[i][j] = maximum joy level by giving i people j cards
ll ans;

int main() {
	scanf("%d%d", &n, &k);
	REP (i, 0, n * k) {
		int c; scanf("%d", &c);
		cnt[c]++;
	}
	REP (i, 1, n + 1) {
		scanf("%d", &f[i]);
		cntf[f[i]]++;
	}
	REP (i, 1, k + 1) {
		scanf("%d", &h[i]);
	}
	REP (i, 1, n + 1) {
		REP (j, 1, n * k + 1) {
			REP (l, 0, k + 1) {
				if (j - l < 0) continue;
				mxto(dp[i][j], dp[i - 1][j - l] + h[l]);
			}
		}
	}
	REP (i, 0, MAX) {
		if (cntf[i] == 0) continue;
		ans += dp[cntf[i]][cnt[i]];
	}
	printf("%lld\n", ans);
}