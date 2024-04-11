#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define tysiac 1010
#define milion 1000100
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define OUT(x) { cout << x; return 0; }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <ld, ld> PDD;
typedef pair <PII, PII> PP;
typedef pair <ll, int> PLI;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
#define maxn 1000100

int t[maxn], n, a;

int dp[maxn][3];

int main() {
	scanf("%d", &n);
	FOR(i, 1, n) scanf("%d", &t[i]);
	int wyn = 0;
	FOR(i, 1, n) {
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
		dp[i][0] = max(dp[i][0], dp[i-1][2]);
		//1 - gym
		if (t[i] == 2 || t[i] == 3) dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + 1;
		if (t[i] == 1 || t[i] == 3) dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + 1;
		FOR(j, 0, 2) wyn = max(wyn, dp[i][j]);
	}
	printf("%d\n", n - wyn);
}