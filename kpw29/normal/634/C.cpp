#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define e1 first
#define e2 second
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef unsigned long long int ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
const int mod = 100;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 4e18 + 3;
#define maxn 1500100
const int R = (1 << 19);
int dr[maxn][2], A, B;
int st[3];

void update(int x, int ile, int par)
{
	x += R-1;
	dr[x][par] += ile;
	dr[x][par] = min(dr[x][par], st[par]);
	x>>=1;
	while (x)
	{
		dr[x][par] = dr[2 * x][par] + dr[2 * x + 1][par];
		x >>= 1;
	}
}

int query(int x, int y, int par)
{
	if (x > y) return 0;
	x += R-1; y += R-1;
	int ret = dr[x][par];
	if (x != y) ret += dr[y][par];
	while (x / 2 != y / 2)
	{
		if (!(x & 1)) ret += dr[x + 1][par];
		if (y & 1) ret += dr[y - 1][par];
		x>>=1; y>>=1;
	}
	return ret;
}

int n, k, zap;

int main()
{
	scanf("%d%d%d%d%d", &n, &k, &st[1], &st[0], &zap);
	while (zap--)
	{
		int tp;
		scanf("%d", &tp);
		if (tp == 1)
		{
			int day, ile;
			scanf("%d%d", &day, &ile);
			update(day, ile, 0);
			update(day, ile, 1);
		}
		else
		{
			int day;
			scanf("%d", &day);
			int ret = 0;
			ret = query(1, day - 1, 0) + query(day + k, n, 1);
			printf("%d\n", ret);
		}
	}
	
}