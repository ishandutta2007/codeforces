#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false);}
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 150
int n, m;
char init[maxn][maxn], goal[maxn][maxn];
vector <PII> ret;

inline bool pion(int x, int y) {
	return init[x][y] == 'U';
}
inline bool poziom(int x, int y) {
	return init[x][y] == 'L';
}
inline void doSwap(int x, int y) //swapping things with upper left corner (x, y)
{
	//cout << "Swapping: " << x << ' ' << y << endl;
	//assuming that swap is valid
	ret.pb(mp(x, y));
	if (init[x][y] == 'L') {
		assert(init[x][y+1] == 'R');
		assert(init[x+1][y] == 'L');
		assert(init[x+1][y+1] == 'R');
		init[x][y] = init[x][y+1] = 'U';
		init[x+1][y] = init[x+1][y+1] = 'D';
	}
	else if (init[x][y] == 'U') {
		assert(init[x][y+1] == 'U');
		assert(init[x+1][y] == 'D');
		assert(init[x+1][y+1] == 'D');
		init[x][y] = init[x+1][y] = 'L';
		init[x][y+1] = init[x+1][y+1] = 'R';
	}
}

inline void fixnij(int x, int y)
{
	//cout << "Fixing: " << x << ' ' << y << endl;
	if (pion(x, y) && pion(x, y+1)) {
		doSwap(x, y);
		return;
	}
	if (poziom(x, y) && poziom(x+1, y)) {
		doSwap(x, y);
		return;
	}
	
	if (pion(x, y)) fixnij(x, y+1);
	else fixnij(x+1, y);
	doSwap(x, y);
}

vector <PII> transferToBase()
{
	
	ret.clear();
	if (n % 2 == 0)
	{
		for (int j=1; j<=m; j++)
			for (int i=1; i<=n; i+=2)
			if (!pion(i, j)) fixnij(i, j);
	}
	else
	{
		assert(m % 2 == 0);
		for (int i=1; i<=n; ++i)
			for (int j=1; j<=m; j+=2)
			if (!poziom(i, j)) fixnij(i, j);
	}
	return ret;
}

int main()
{
	scanf("%d%d", &n, &m);
	FOR(i, 1, n) scanf("%s", init[i] + 1);
	FOR(i, 1, n) scanf("%s", goal[i] + 1);
	
	vector<PII> wyn1 = transferToBase();
	
	FOR(i, 1, n)
		FOR(j, 1, m) init[i][j] = goal[i][j];

	
	
	vector<PII> wyn2 = transferToBase();
	//vector<PII> wyn2, wyn1;
	reverse(wyn2.begin(), wyn2.end());
	printf("%d\n", (int)wyn1.size() + (int)wyn2.size());
	for (auto u : wyn1) printf("%d %d\n", u.e1, u.e2);
	for (auto u : wyn2) printf("%d %d\n", u.e1, u.e2);
}