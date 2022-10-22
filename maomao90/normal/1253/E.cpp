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
#define MAXN 85
#define MAXM 100005

int n, m;
int x[MAXN], s[MAXN];
int dp[MAXM], premn[MAXM];

int main() {
	scanf("%d%d", &n, &m);
	REP (i, 0, n) {
		scanf("%d%d", &x[i], &s[i]);
	}
	x[n] = 0; s[n] = 0;
	n++;
	REP (i, 0, m + 1) {
		dp[i] = INF;
	}
	dp[0] = 0;
	premn[0] = 0;
	REP (i, 1, m + 1) {
		REP (j, 0, n) {
			int l = x[j] - s[j], r = x[j] + s[j];
			if (l > i) continue;
			int cost = max(0, i - r);
			r += cost; l -= cost;
			l = max(1, l);
			mnto(dp[i], dp[l - 1] + cost);
			/*
			REP (cost, 0, m + 1) {
				l = max(1, l);
				if (i >= l && i <= r) {
					mnto(dp[i], dp[l - 1] + cost);
				}
				l--; r++;
			}
			*/
		}
		premn[i] = min(premn[i - 1], dp[i] - i);
		//printf("%d: %d\n", i, dp[i]);
	}
	printf("%d\n", dp[m]);
	return 0;
}