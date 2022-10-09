#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define e1 first
#define e2 second
#define pb push_back
#define boost ios_base::sync_with_stdio(false)
#define milion 1000100
#define tysiac 1010
#define dwa_tysiace 2010
#define sto_tysiecy 100100
typedef long long int ll;
typedef unsigned long long int ull;
typedef unsigned int ui;
typedef pair <int, int> BONG;
typedef pair <BONG, BONG> LONG;
const int inf = 1e9+9;
const int mod = 1e9+7;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
int n,m,a,b,c;
#define maxn 3010
int t[maxn];
char s[maxn], help[maxn];
int main()
{
	scanf("%d", &n);
	scanf("%s", s+1);
	int wyn =0;
	for (int i=1; i<=n; ++i) help[i] = s[n-i+1];
	s[0] = 'R'; s[n+1] = 'L';
	for (int i=1; i<=n; ++i)
	if (s[i] == 'R') for (int j=i; s[j] != 'L'; ++j) t[j] = 1;
	else if (s[i] == 'L') for (int j=i; s[j] != 'R'; --j) t[j] = 1;
	for (int i=1; i<=n; ++i) if (t[i] == 0) ++wyn;
	s[0] = '.'; s[n+1] = '.';
	for (int i=1; i<=n; ++i)
	  if (s[i] == '.' && t[i] == 1)
	  {
		  int lew = 0, praw = 0;
		  for (int j=i+1; s[j] != 'L'; ++j) 
		  {
			  if (s[j] == 'R') praw = inf;
			  if (j > n) praw = inf;
			  ++praw;
		  }
		  for (int j=i-1; s[j] != 'R'; --j) 
		  {
			  if (s[j] == 'L') lew = 421723;
			  if (j == 0) lew = 412321;
			  ++lew;
		  }
		  if (lew == praw) ++wyn, t[i] = 0;
	  }
	printf("%d ", wyn);
}