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
int T, n, m, k, a, b, c;
#define maxn 3010

ll dp[100100], pref[100100];
int t[100100], help[100100];

inline ll odl(int a, int b) {
	return max(b - a, a -b);
}

int main() {
	boost;
	cin >> n;
	m = 0;
	FOR(i, 1, n) {
		cin >> t[i];
		t[i] -= i;
		help[++m] = t[i];
	}
	sort(help + 1, help + m + 1);
	
	FOR(i, 1, n) {
		FOR(j, 1, m) {
			ll cost = odl(help[j], t[i]);
			dp[j] = pref[j] + cost;
		}
		FOR(j, 0, m) pref[j] = INF;
		FOR(j, 1, m) pref[j] = min(pref[j-1], dp[j]);
	}
	
	cout << pref[m];
}