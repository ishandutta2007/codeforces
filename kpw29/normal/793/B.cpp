#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
int n, m, a, b, k,c;
#define maxn 1010
char s[1010][1010];
int pref[maxn][maxn];

inline int sum(int a, int b, int c, int d)
{
	if (b > d) swap(a, c), swap(b, d);
	if (a > c) swap(a, c), swap(b, d);
	return pref[c][d] - pref[a-1][d] - pref[c][b-1] + pref[a-1][b-1];
}

int main()
{
	scanf("%d%d", &n, &m);
	FOR(i, 1, n) scanf("%s", s[i] +1);
	int X1, Y1, Y2, X2;
	bool ans = 0;
	FOR(i, 1, n)
		FOR(j, 1, m)
		{
			int aa = 0;
			if (s[i][j] == 'S') X1 = i, Y1 = j;
			if (s[i][j] == 'T') X2 = i, Y2 = j;
			if (s[i][j] == '*') aa = 1;
			pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + aa;
		}
	
	FOR(i, 1, m)
	{
		int s1 = sum(X1, Y1, X1, i) + sum(X1, i, X2, i) + sum(X2, i, X2, Y2);
		if (s1 == 0) ans = 1;
	}
	FOR(i, 1, n)
	{
		int s1 = sum(X1, Y1, i, Y1) + sum(i, Y1, i, Y2) + sum(i, Y2, X2, Y2);
		if (s1 == 0) ans = 1;
	}
	if (ans) cout << "YES";
	else cout << "NO";
		
}