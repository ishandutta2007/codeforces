#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); }
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
typedef pair <PLL, PLL > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 2000100;
int cnt[maxn], n, m, wym, mx;
int xd[maxn];

bool help(int x, int y)
{
	fill(xd, xd+maxn, 0);
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=m; ++j) xd[abs(i-x) + abs(j-y)]++;
	
	FOR(i, 0, n+m)
		if (cnt[i] != xd[i]) return false;

	return true;
}

void check()
{
	PII pos = {0, 0};
	int dist = mx;
	if (dist < m) pos = {1, dist + 1};
	else pos = {dist - m + 2, m};
	
	int nok = 1;
	while (cnt[nok] == 4 * nok) ++nok;
	while (pos.e2 > 0)
	{
		int i = pos.e1; 
		int j = pos.e2;
		int mn = min(i, j);
		mn = min(mn, n-i+1);
		mn = min(mn, m-j+1);
		if (mn == nok && help(pos.e1, pos.e2))
		{
			cout << n << ' ' << m << endl;
			cout << i << ' ' << j << endl;
			exit(0);
		}
		
		pos.e2--; pos.e1++;
	}
}

int main()
{
	boost;
	cin >> wym;
	mx = 0;
	FOR(i, 1, wym) {
		int p;
		cin >> p;
		mx = max(mx, p);
		cnt[p]++;
	}
	
	if (cnt[0] != 1) OUT(-1);
	
	if (wym == 1) {
		OUT("1 1\n1 1");
	}
	
	FOR(i, 1, wym)
		if (wym % i == 0)
		{
			n = i;
			m = wym / i;
			check();
		}
	
	OUT(-1);
}