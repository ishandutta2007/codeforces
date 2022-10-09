#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 4010
int n, m, a, b, c;
int tab[1010][2];
int main()
{
	cin >> n >> m;
	if (m == 0) 
	{
		if (n > 1) OUT("-1 -1");
		OUT("0 0");
	}
	tab[1][0] = 1;
	for (int i=1; i<=n; ++i) tab[i][1] = 9;
	int s1 = 1;
	for (int i=n; i>0; --i)
		if (s1 <= m)
		{
			int diff = min(9 - tab[i][0], m - s1);
			s1 += diff;
			tab[i][0] += diff;
		}
	int s2 = 9 * n;
	for (int i=n; i>0; --i)
	    if (s2 > m)
	    {
	    	int diff = min(tab[i][1], s2 - m);
	    	s2 -= diff;
	    	tab[i][1] -= diff;
	    }
	if (s1 != m) cout << "-1 ";
	else 
	{
		for (int i=1; i<=n; ++i) cout << tab[i][0];
		cout << " ";
	}
	if (s2 != m) cout << "-1";
	else for (int i=1; i<=n; ++i) cout << tab[i][1];
}