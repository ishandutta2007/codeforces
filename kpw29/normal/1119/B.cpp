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
const int maxn = 300010;
int n, tab[maxn];
int help[maxn];
ll h;
bool ok(int x)
{
	if (x == n + 1) return 0;
	FOR(i, 1, x) help[i] = tab[i];
	sort(help+1, help+x+1);
	ll sum = 0;
	for (int i = x; i > 0; i -= 2) sum += help[i];
	if (sum <= h) return true;
	return false;
}

int main()
{
	boost;
	cin >> n >> h;
	FOR(i, 1, n) cin >> tab[i];
	FOR(i, 1, n + 1)
		if (!ok(i)) {
			cout << i - 1;
			exit(0);
		}
}