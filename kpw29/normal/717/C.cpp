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
typedef pair <double, int> PDI;

const int mod = 1e4+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int T, n, m, K, a, b, c, k, d, g, Q, DL;

#define maxn 1000100
ll t[maxn];
int main() {
	boost;
	cin >> n;
	FOR(i, 1, n) cin >> t[i];
	sort(t + 1, t + n + 1);
	ll wyn = 0;
	FOR(i, 1, n) wyn += ( t[i] * t[n - i + 1]);
	cout << (wyn % mod);
}