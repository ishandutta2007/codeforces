#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef unsigned int ui;
const ll mod = 1e9 +7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 5010

char s[maxn];
ll pref[maxn][maxn];
int t[maxn][20], n;
PP help[maxn];

void KMR(int LOG)
{
	t[n+1][0] = 0;
	for (int i=1; i<=n; ++i) t[i][0] = s[i] - 'a' + 1;
	for (int j=1; j<=LOG; ++j)
	{
		for (int i=1; i<=n; ++i) 
		  if (i + (1<<(j-1)) <= n) help[i] = mp(mp(t[i][j-1], t[i+(1<<(j-1))][j-1]), mp(i, 0));
		  else help[i] = mp(mp(t[i][j-1], 0), mp(i, 0));
		sort(help+1, help+n+1);
		int act = 0;
		for (int i=1; i<=n; ++i) 
		  if (help[i].e1.e1 == help[i-1].e1.e1 && help[i].e1.e2 == help[i-1].e1.e2) t[help[i].e2.e1][j] = act;
		  else t[help[i].e2.e1][j] = ++act;
	}
}
inline int lgbit(int x) {
	return (sizeof(int)<<3)-__builtin_clz(x)-1;
}
bool thesame(int a, int b, int c, int d)
{
	int dl = (d - c + 1);
	//if (a == 1 && c == 5) printf("por %d\n", dl);
	int POT = (1 << lgbit(dl)), DOT = lgbit(dl);
	if (t[a][DOT] == t[c][DOT] && t[b - POT + 1][DOT] == t[d - POT + 1][DOT]) return 1;
	return 0;
}

bool mniejsze(int a, int b, int c, int d)
{
	
	if (d - c > b - a) return 1;
	if (d - c < b - a) return 0;
	
	int x = 0, y = d - c;
	while (x < y)
	{	
		int sr = (x + y) >> 1;
		if (thesame(a, a + sr, c, c + sr)) x = sr + 1;
		else y = sr;
	}
	//if (a == 1 && c == 5) printf("%d\n", x);
	if (s[a + x] < s[c + x]) return true;
	return false;
}
bool chk(int i, int j, int a, int b)
{
	if (a < 1 || b < 1) return 1;
	bool m = mniejsze(i, j, a, b);
	/* {
			  for (int h=i; h<=j; ++h) printf("%c", s[h]);
			  if (m) printf(" < ");
			  else printf(" > ");
			  for (int h=a; h<=b; ++h) printf("%c", s[h]);
			  puts("");
	}*/
	return m;
}
int main()
{
	scanf("%d", &n);
	scanf("%s", s+1);
	s[n + 1] = (char)(159);
	KMR(14);	
	for (int i=0; i<=n; ++i) pref[0][i] = 1;
	for (int i=1; i<=n; ++i) pref[1][i] = 1;

	for (int i=2; i<=n; ++i)
	{
	  for (int j=i; j>0; --j)
	  {
		  if (s[j] == '0') continue;
		  if (chk(2*j - i - 1, j - 1, j, i)) {
			  pref[i][(i-j+1)] += pref[j - 1][(i-j+1)];
		  }
		  else pref[i][(i-j+1)] += pref[j-1][(i - j)];
		  pref[i][i-j+1] %= mod;
	  }
	  for (int j=1; j<=n; ++j) pref[i][j] += pref[i][j-1], pref[i][j] %= mod;
	}

  cout << pref[n][n] % mod;
}