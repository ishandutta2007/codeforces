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
#define MAXN 15
#define MAXM 33000
#define MAXT 225

int n, t;
ii tg[MAXN];
int memo[5][MAXM][MAXT + 2];
int dp(int g, int msk, int remt) {
	if (remt == 0) return 1;
	if (remt < 0) return 0;
	if (msk == (1 << n) - 1) return 0;
	if (memo[g][msk][remt] != -1) return memo[g][msk][remt];
	ll res = 0;
	REP (i, 0, n) {
		if (msk & (1 << i)) continue;
		if (tg[i].SE == g) continue;
		res += dp(tg[i].SE, msk | (1 << i), remt - tg[i].FI);
		res %= MOD;
	}
	return memo[g][msk][remt] = res;
}


int main() {
	scanf("%d%d", &n, &t);
	REP (i, 0, n) {
		scanf("%d%d", &tg[i].FI, &tg[i].SE);
	}
	memset(memo, -1, sizeof memo);
	printf("%d\n", dp(4, 0, t));
	return 0;
}