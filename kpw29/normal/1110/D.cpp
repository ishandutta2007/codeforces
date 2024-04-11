#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define REYNA(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, pair <int, ll> > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
int n, m;
const int maxn = 1001000;
int dp[maxn][8][8]; //dp[n][post][ost]

inline int f(int x) {return x / 3; }
inline void maxuj(int &x, int val) {x = max(x, val); }
int sc[maxn];

int main()
{
	boost;
	cin >> n >> m;
	FOR(i, 1, n) {
		int a;
		cin >> a;
		sc[a + 2]++;
	}
	int M = 1000010;
	int ret = 0;
	FOR(i, 3, M)
	{
		FOR(j, 0, 7)
			FOR(k, 0, 7) {
				if (sc[i - 2] >= j && sc[i - 1] >= k) {
					maxuj(dp[i][k][0], dp[i-1][j][k] + f(sc[i - 2] - j));
				}
				if (sc[i - 2] >= j + 1 && sc[i - 1] >= k + 1 && sc[i] >= 1 && j + 1 < 8 && k + 1 < 8) {
					maxuj(dp[i][k+1][1], dp[i-1][j][k] + f(sc[i - 2] - j - 1) + 1);
				}
				if (sc[i - 2] >= j + 2 && sc[i - 1] >= k + 2 && sc[i] >= 2 && j + 2 < 8 && k + 2 < 8) {
					maxuj(dp[i][k+2][2], dp[i-1][j][k] + f(sc[i - 2] - j - 2) + 2);
				}
				
			}
		
		FOR(j, 0, 4)
			FOR(k, 0, 4) {
				ret = max(ret, dp[i][j][k]);
			}

	}
	
	cout << ret;
}