#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define tysiac 1010
#define milion 1000100
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <ld, ld> PDD;
typedef pair <PII, PII> PP;
typedef pair <ll, int> PLI;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int a,b,c,k,x, out, in;
#define OUT(x) {cout << x; return 0; }
int t[21], POT, bits[21], m;
ll tab[(1 << 18) + 5][102];
char s[30];
int card[10];
ll silnia[20];
int main()
{
	scanf("%s%d" ,s+1, &m);
	silnia[0] = 1;
	for (ll i=1; i<=18; ++i) silnia[i] = silnia[i-1] * i;
	int n = 1;
	while (s[n]) ++n; --n;
	for (int i=1; i<=n; ++i) t[i] = s[i] - '0';
	sort(t+1, t+n+1);
	POT = (1 << n);
	tab[0][0] = 1;
	for (int i=1; i<POT; ++i)
	{
		int help = i, sum = 0;
		for (int j=1; j<=n; ++j) {
		if (help & 1) bits[j] = 1, sum += t[j];
		else bits[j] = 0;
		help >>= 1;
		}
		for (int j=0; j<10; ++j) card[j] = 0;
		for (int j=1; j<=n; ++j)
		  if (bits[j]) card[t[j]]++;
		ll DIV = 1;
		for (int j=0; j<10; ++j) DIV *= silnia[card[j]];
		if (sum == 0) continue; //absolutely nothing could we do with this state cuz all zeros are
		for (int j=1; j<=n; ++j)
		if (bits[j])
		{
			int el = (1 << (j -1));
			for (int help=0; help<m; ++help) 
			{
				int nowa_wart = ((help << 3) + (help << 1) + t[j]) % m;
				tab[i][nowa_wart] += tab[i ^ el][help];
			}
		}
		
		if (i == POT - 1) for (int j=0; j<m; ++j) tab[i][j] /= DIV;
	}

	ll ret = 0;
	ret += tab[POT - 1][0];
	cout << ret;
}