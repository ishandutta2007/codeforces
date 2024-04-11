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
const int maxn = 252;
int nast[100010][26];
char s[100100];
int n, m, q;

int ile[4];
int tab[4][maxn];

int dp[maxn][maxn][maxn];

void addCharacter(int which, char zn)
{
	ile[which]++;
	tab[which][ile[which]] = zn - 'a';
	
	if (which == 1)
	{
		int w = ile[1];
		//recalc for dp[ile[1]][b][]
		FOR(b, 0, ile[2])
			FOR(c, 0, ile[3])
			{
				dp[w][b][c] = n + 1;
				//zmieniam pierwsza literke
				if (w) dp[w][b][c] = min(dp[w][b][c], nast[dp[w-1][b][c]][tab[1][w]]);
				if (b) dp[w][b][c] = min(dp[w][b][c], nast[dp[w][b-1][c]][tab[2][b]]);
				if (c) dp[w][b][c] = min(dp[w][b][c], nast[dp[w][b][c-1]][tab[3][c]]);
			}
	}
	
	if (which == 2)
	{
		int w = ile[2];
		FOR(a, 0, ile[1])
		FOR(c, 0, ile[3])
		{
			dp[a][w][c] = n + 1;
			if (a) dp[a][w][c] = min(dp[a][w][c], nast[dp[a-1][w][c]][tab[1][a]]);
			if (w) dp[a][w][c] = min(dp[a][w][c], nast[dp[a][w-1][c]][tab[2][w]]);
			if (c) dp[a][w][c] = min(dp[a][w][c], nast[dp[a][w][c-1]][tab[3][c]]);
		}
	}
	
	if (which == 3)
	{
		int w = ile[3];
		FOR(a, 0, ile[1])
		FOR(b, 0, ile[2])
		{
			dp[a][b][w] = n + 1;
			if (a) dp[a][b][w] = min(dp[a][b][w], nast[dp[a-1][b][w]][tab[1][a]]);
			if (b) dp[a][b][w] = min(dp[a][b][w], nast[dp[a][b-1][w]][tab[2][b]]);
			if (w) dp[a][b][w] = min(dp[a][b][w], nast[dp[a][b][w-1]][tab[3][w]]);		
		}
	}
}

void undo(int which)
{
	--ile[which]; //and that's it
}

int main()
{
	dp[0][0][0] = 0;
	scanf("%d%d", &n, &q);
	scanf("%s", s+1);
	FOR(j, 0, 25) nast[n][j] = nast[n + 1][j] = n + 1;
	for (int i=n-1; i>=0; --i) {
		for (int j=0; j<26; ++j) nast[i][j] = nast[i+1][j];
		nast[i][s[i+1]-'a'] = i + 1;
	}
	
	while (q--) {
		char tmp, letter;
		int which;
		scanf(" %c%d", &tmp, &which);
		if (tmp == '+') {
			scanf(" %c", &letter);
			addCharacter(which, letter);
		}
		else undo(which);
		
		if (dp[ile[1]][ile[2]][ile[3]] <= n) puts("YES");
		else puts("NO");
	}
}