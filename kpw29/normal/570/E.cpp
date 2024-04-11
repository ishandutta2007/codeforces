#include <bits/stdc++.h>
#include <string>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned int ull;
typedef pair <int, int> PII;
typedef pair <PII, int> PPI;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int inf = 1e9+9;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 510
int dp[2][maxn][maxn], n, m, k; //dp[ktory_rzad][pole1][pole2]
int pole[maxn][maxn];
PII odw[1010][maxn];

char s[maxn][maxn], t[maxn][maxn];

inline int dajWsp(int i, int j) {
	int diff = n + m - (i + j) + 1;
	if (diff >= n) return i;
	return i - (n - diff);
}

inline int liczba(int warstwa) {
	if (warstwa < n) return warstwa;
	if (warstwa > m) return (n + m - warstwa + 1);
	return n;
}

inline void moduluj(int &x) {
	while (x >= mod) x -= mod;
}

int main() {
	scanf("%d%d", &n, &m);
	FOR(i, 1, n) scanf("%s", t[i] + 1);
	if (n > m)
	{
		FOR(i, 1, n)
		  FOR(j, 1, m) s[j][i] = t[i][j];
		swap(n, m);
	}
	else
	{
		FOR(i, 1, n)
		  FOR(j, 1, m) s[i][j] = t[i][j];
	}
	FOR(i, 1, n)
	  FOR(j, 1, m) 
	  {
		  pole[i][j] = dajWsp(i, j);
		  odw[i+j][pole[i][j]] = mp(i, j);
	  }
  
	if (s[1][1] == s[n][m]) dp[0][1][1] = 1;
	else OUT(0);

	int wyn = 0;
	
	int wh = (m + n) / 2;
	for (int warstwa=3; warstwa <= wh + 1; ++warstwa)
	{
		int ile = liczba(warstwa);
		for (int kt = 1; kt <= ile; ++kt)
		{
			int i = odw[warstwa][kt].e1, j = odw[warstwa][kt].e2;
			int layer = i + j, druga = m + n - layer + 2;
			int lll = (layer & 1);
			int nr = pole[i][j], lec=liczba(druga);
			
			for (int gdzie=1; gdzie<=lec; ++gdzie)
			{
				dp[lll][nr][gdzie] = 0;
				
				//mamy wyznaczone dwa pola do ktorych bedziemy probowali dojsc
				//dp[layer][nr][gdzie];
				int xx = odw[druga][gdzie].e1, yy = odw[druga][gdzie].e2;
				if (s[xx][yy] != s[i][j]) continue;
				if (i > 1 && xx < n)
				{
					dp[lll][nr][gdzie] += dp[lll^1][pole[i-1][j]][pole[xx+1][yy]];
					moduluj(dp[lll][nr][gdzie]);
				}
				if (i > 1 && yy < m)
				{
					dp[lll][nr][gdzie] += dp[lll^1][pole[i-1][j]][pole[xx][yy+1]];
					moduluj(dp[lll][nr][gdzie]);
				}
				if (j > 1 && xx < n)
				{
					dp[lll][nr][gdzie] += dp[lll^1][pole[i][j-1]][pole[xx+1][yy]];
					moduluj(dp[lll][nr][gdzie]);
				}
				if (j > 1 && yy < m)
				{
					dp[lll][nr][gdzie] += dp[lll^1][pole[i][j-1]][pole[xx][yy+1]];
					moduluj(dp[lll][nr][gdzie]);
				}
				
				//cout << "warstwa : " << layer << " Warstwa nr 2 : " << druga << " nr: " << nr << " gdzie : " << gdzie << ' ' << dp[lll][nr][gdzie] << endl;
			}
			
		}
	}
	
	int half = (m + n) / 2;
	int r = (half & 1);
	if ((m + n)	& 1)
	{
		
		FOR(i, 1, n)
		  FOR(j, 1, m)
		  if (i + j == half + 1) {
			//  cout << i << ' ' << j << endl;
			  if (i < n) wyn += dp[r^1][pole[i][j]][pole[i+1][j]];
			  moduluj(wyn);
			  if (j < m) wyn += dp[r^1][pole[i][j]][pole[i][j+1]];
			  moduluj(wyn);
			 // cout << wyn << endl;
		  }
	}
	else
	{
		FOR(i, 1, n)
		  FOR(j, 1, m)
		    if (i + j == half + 1) {
				wyn += dp[r^1][pole[i][j]][pole[i][j]];
				moduluj(wyn);
			}
	}
	
	cout << wyn;
}