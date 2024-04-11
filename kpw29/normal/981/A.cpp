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
const int mod = 1e9+7;
const int inf = 1e9+9;
const int maxn = 1000100;
int n, m, k, a, b, c;
int tab[maxn];
bool pal[210][210];

int main()
{
	boost;
	string s;
	cin >> s;
	n = s.length();
	int res = 0;
	FOR(i, 0, 100)
		FOR(j, 0, 100)
			if (i >= j) pal[i][j] = 1;
			
	FOR(len, 1, n)
	{
		for (int i=0; i<n-len+1; ++i)
		{
			int j = i + len - 1;
			if (s[i] != s[j]) pal[i][j] = 0;
			else 
			{
				if (len == 1) pal[i][j] = 1;
				else if (len == 2) pal[i][j] = 1;
				else pal[i][j] = pal[i + 1][j - 1];
			}
		}
	}
	
	FOR(i, 0, n-1)
		FOR(j, i, n-1)
			if (!pal[i][j]) res = max(res, j - i + 1);
	
	cout << res;
}