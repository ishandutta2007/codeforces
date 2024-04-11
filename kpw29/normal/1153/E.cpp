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
const int maxn = 1010;

int x[maxn], y[maxn], n;

void answer(int x1, int y1, int x2, int y2)
{
	printf("! %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);
	exit(0);
}

int ask(int x1, int y1, int x2, int y2)
{
	printf("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);
	int ans;
	scanf("%d", &ans);
	return ans;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) x[i] = ask(i, 1, i, n);
	for (int i=1; i<=n; ++i) y[i] = ask(1, i, n, i);
	vector <int> vx, vy;
	FOR(i, 1, n)
		if (x[i] % 2) vx.pb(i);
	
	FOR(i, 1, n)
		if (y[i] % 2) vy.pb(i);
	
	assert((int)vx.size() == 2 || (int)vx.size() == 0);
	assert((int)vy.size() == 2 || (int)vy.size() == 0);
	
	int sx = vx.size(), sy = vy.size();
	if (sx && sy)
	{
		if (ask(vx[0], vy[0], vx[0], vy[0]) % 2) answer(vx[0], vy[0], vx[1], vy[1]);
		else answer(vx[0], vy[1], vx[1], vy[0]);
	}
	
	else
	{
		if (sx == 0)
		{
			int a = 1, b = n;
			while (a < b)
			{
				int sr = (a + b) / 2;
				if (ask(a, 1, sr, vy[0]) % 2 == 0) a = sr + 1;
				else b = sr;
			}
			
			answer(a, vy[0], a, vy[1]);
		}
		else
		{
			int a = 1, b = n;
			while (a < b)
			{
				int sr = (a + b) / 2;
				if (ask(1, a, vx[0], sr) % 2 == 0) a = sr + 1;
				else b = sr;
			}
			
			answer(vx[0], a, vx[1], a);
		}
	}
}