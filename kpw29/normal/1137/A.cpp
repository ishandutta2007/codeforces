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
int tab[maxn][maxn];
int posx[maxn][maxn], largex[maxn][maxn], posy[maxn][maxn], largey[maxn][maxn];

int n, m;
PII help[maxn];

int main()
{
	boost;
	cin >> n >> m;
	FOR(i, 1, n)
		FOR(j, 1, m) cin >> tab[i][j];
	
	FOR(row, 1, n)
	{
		FOR(i, 1, m) help[i] = mp(tab[row][i], i);
		sort(help+1, help+m+1);
		help[m + 1].e1 = -1;
		int score = 0;
		int wsk = m;
		for (int i=m; i>0; --i) {
			while (help[wsk].e1 > help[i].e1) {
				if (help[wsk].e1 != help[wsk + 1].e1) ++score;
				--wsk;
			}
			largex[row][help[i].e2] = score;
		}
		
		score = 0;
		help[0].e1 = -1;
		
		for (int i=1; i<=m; ++i) {
			if (help[i].e1 > help[i-1].e1) {
				++score;
			}
			posx[row][help[i].e2] = score;
		}
	}
	
	FOR(col, 1, m)
	{
		FOR(i, 1, n) help[i] = mp(tab[i][col], i);
		sort(help+1, help+n+1);
		int score = 0;
		int wsk = n;
		help[n + 1].e1 = -1;
		for (int i=n; i>0; --i) {
			while (help[wsk].e1 > help[i].e1) {
				if (help[wsk].e1 != help[wsk + 1].e1) ++score;
				--wsk;
			}
			largey[help[i].e2][col] = score;
		}
		
		score = 0;
		help[0].e1 = -1;
		
		for (int i=1; i<=n; ++i) {
			if (help[i].e1 > help[i-1].e1) {
				++score;
			}
			posy[help[i].e2][col] = score;
		}
	}
	
	FOR(i, 1, n) {
		FOR(j, 1, m) cout << max(posx[i][j], posy[i][j]) + max(largex[i][j], largey[i][j]) << ' ';
		cout << "\n";
	}
	
}