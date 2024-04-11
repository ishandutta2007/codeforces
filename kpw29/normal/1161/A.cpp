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
const int maxn = 1000003;
int n, m;
int tab[maxn];
ll ans;
int ost[maxn];
int fst[maxn];

void score(int x, int y)
{
	if (y > n || y == 0) return;
	if (!ost[x]) ++ans;
	else
	{
		if (fst[x] > ost[y]) ++ans;
	}
}

int main()
{
	boost;
	ans = 0;
	cin >> n >> m;
	ost[0] = ost[n + 1] = m + 1;
	
	FOR(i, 1, m) {
		int a;
		cin >> a;
		ost[a] = i;
		if (!fst[a]) fst[a] = i;
	}
	
	FOR(i, 1, n) {
		if (!ost[i]) ++ans;
		score(i, i+1);
		score(i, i-1);
	}
	
	cout << ans;
}