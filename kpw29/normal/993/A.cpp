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
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 0;
int tab[10][2];
PII mid[3];
int bokk[3];

inline int dist(PII a, PII b) {
	return abs(a.e1 - b.e1) + abs(a.e2 - b.e2);
}

bool isRev(int KT, int a, int b)
{
	int xx = 0, yy = 0;
	FOR(i, a, b) xx += tab[i][0], yy += tab[i][1];
	if (xx % 4 != 0 || yy % 4 != 0) return 0; //not rev
	mid[KT] = mp(xx / 4, yy / 4);
	int bok = dist(mid[KT], mp(tab[a][0], tab[a][1]));
	
	for (int i=a; i<=b; ++i)
		if (dist(mid[KT], mp(tab[i][0], tab[i][1])) != bok) return 0;
	int cnt = 0;
	
	for (int i=a; i<=b; ++i)
		if (tab[i][0] == mid[KT].e1 || tab[i][1] == mid[KT].e2) ++cnt;
	
	if (cnt != 4) return 0;
	bokk[KT] = bok;
	return 1;
}
bool is1, is2;
int ktory;

bool inside(int i, int j)
{
	return dist(mp(i, j), mid[ktory]) <= bokk[ktory];
}

int main()
{
	FOR(i, 1, 4) cin >> tab[i][0] >> tab[i][1];
	FOR(i, 5, 8) cin >> tab[i][0] >> tab[i][1];
	bokk[0] = bokk[1] = -1;
	is1 = isRev(0, 1, 4);
	is2 = isRev(1, 5, 8);
	int MINX = 200, MINY = 200, MAXX = -200, MAXY = -200;
	if (is1)
	{
		ktory = 0;
		assert(!is2);
		FOR(i, 5, 8)
		{
			MINX = min(MINX, tab[i][0]);
			MAXX = max(MAXX, tab[i][0]);
			MINY = min(MINY, tab[i][1]);
			MAXY = max(MAXY, tab[i][1]);
		}
	}
	else
	{
		ktory = 1;
		assert(is2);
		FOR(i, 1, 4)
		{
			MINX = min(MINX, tab[i][0]);
			MAXX = max(MAXX, tab[i][0]);
			MINY = min(MINY, tab[i][1]);
			MAXY = max(MAXY, tab[i][1]);
		}
	}

	FOR(i, MINX, MAXX)
		FOR(j, MINY, MAXY)
			if (inside(i, j)) OUT("YES");
	
	cout << "NO";
}