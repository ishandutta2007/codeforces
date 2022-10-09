#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned int ull;
typedef pair <int, int> PII;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
typedef unsigned int ui;
const int inf = 1e9+9;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100

ll dp[100];

int main() {
	ll players = 2;
	ll n;
	cin >> n;
	if (n == 2) OUT(1);
	dp[0] = 1; //1 graczy gra
	dp[1] = 2; //2 graczy gra
	FOR(i, 2, 100) {
		players += dp[i-1];
		dp[i] = dp[i-1] + dp[i-2];
		//cout << dp[i] << endl;
		if (dp[i] > n) OUT(i - 1);
	}
}