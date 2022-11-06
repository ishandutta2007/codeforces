#include <cstdio>
#include <algorithm> 
#define mod 998244353

char s[201000];
int p[26][201000], mi[201000];
int a[26], b[26];

int get_hash(int c, int l, int r)
{
	return ( p[c][r] - 1ll * p[c][l - 1] * mi[r - l + 1] % mod + mod ) % mod;
}

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	mi[0] = 1; for(int i = 1; i <= n; i++) mi[i] = mi[i - 1] * 2 % mod;
	for(int c = 0; c < 26; c++)
		for(int i = 1; i <= n; i++)
		{
			p[c][i] = ( p[c][i - 1] * 2 + (c + 'a' == s[i]) ) % mod;
		}
	for(int i = 1; i <= m; i++)
	{
		int x, y, len; scanf("%d%d%d", &x, &y, &len);
		for(int c = 0; c < 26; c++)
			a[c] = get_hash(c, x, x + len - 1);
		for(int c = 0; c < 26; c++)
			b[c] = get_hash(c, y, y + len - 1);
		std::sort(a, a + 26);
		std::sort(b, b + 26);
		bool ok = 0;
		for(int c = 0; c < 26; c++) if(a[c] != b[c]) {ok = 1; break;}
		if(!ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
s   t   
 
2601hash 
26s26hasht26hash 
*/