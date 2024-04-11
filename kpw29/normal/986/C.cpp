#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REYNA(i, a, b) for (int i=(a); i<(b); ++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PII, PII> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const ll INF = 1e18;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int maxn = (1 << 22);

int n, m;
bitset <maxn> odw, jest;
int tab[maxn];
int f[maxn];
inline int find(int a)
{
	if (f[a] == a) return a;
	f[a] = find(f[a]);
	return f[a];
}
int c;

void lacz(int a, int b)
{
	a = find(a); b = find(b);
	
	if (a == b) return;
	c--;
	if (a & 1) f[a] = b;
	else f[b] = a;
}

int best[maxn][5];
const int C = 3;
const int D = 50;

int main()
{
	boost;
	cin >> m >> n;
	c = n;
	FOR(i, 0, (1 << m)-1) 
	{
		f[i] = i;
		FOR(j, 0, C-1) best[i][j] = inf;
	}
	
	FOR(i, 1, n) 
	{
		cin >> tab[i];
		jest[tab[i]] = 1;
		if (tab[i] == 0) OUT(1);
		best[tab[i]][0] = tab[i];
	}
	
	int pot = (1 << m);
	FOR(i, 0, pot -1)
	{
		FOR(j, 0, m - 1)
			if (i & (1 << j)) 
			{
				int st = 0;
				FOR(kc, 0, C-1)
				{
					int xd = best[i ^ (1 << j)][kc];
					if (xd != inf)
					{
						while (st < C && best[i][st] < xd) ++st;
						if (best[i][st] == xd) continue;
						for (int iter = C - 1; iter > st; --iter) best[i][iter] = best[i][iter - 1];
						if (st < C) best[i][st] = xd;
					}
				}
			}
	}
	
	FOR(i, 1, n)
	{
		int pp = 0;
		FOR(j, 0, m-1)
		{
			int bit = (tab[i] & (1 << j))?0:1;
			pp += bit * (1 << j);
		}
				
		FOR(iter, 0, C-1) 
			if (best[pp][iter] != inf) lacz(best[pp][iter], tab[i]);
	}
		
	cout << c << endl;
}