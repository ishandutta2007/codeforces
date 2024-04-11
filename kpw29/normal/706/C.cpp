#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define x first
#define y second
#define tysiac 1010
#define milion 1000100
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define OUT(x) { cout << x; return 0; }
#define PRINT(x, y) {printf("%d %d\n", x, y); return;} 
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
int T, n, m, k, a, b, c, d, g, Q, DL;
#define maxn 100100
int cost[maxn];
string s;

ll DP[maxn][2];

int main() {
	boost;
	cin >> n;
	FOR(i, 1, n) cin >> cost[i];
	string l1 = "", l2 = "";
	DP[0][0] = DP[0][1] = 0;
	
	FOR(i, 1, n) {
		string s1, s2;
		cin >> s1;
		DP[i][0] = INF, DP[i][1] = INF;
		s2 = s1;
		reverse(s2.begin(), s2.end());
		if (l1 <= s1) DP[i][0] = min(DP[i][0], DP[i-1][0]);
		if (l1 <= s2) DP[i][1] = min(DP[i][1], DP[i-1][0] + cost[i]);
		if (l2 <= s1) DP[i][0] = min(DP[i][0], DP[i-1][1]);
		if (l2 <= s2) DP[i][1] = min(DP[i][1], DP[i-1][1] + cost[i]);
		l1 = s1; l2 = s2;
		//cout << DP[i][0] << ' ' << DP[i][1] << endl;
	}
	
	ll wyn = min(DP[n][0], DP[n][1]);
	if (wyn == INF) cout << -1;
	else cout << wyn;
}