#include <bits/stdc++.h>
#define FOR(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
using namespace std;
char s[110][110],ans[110];
int n,m,i,j,a[110],len,x;
bool f[110];
int main()
{
	scanf("%d%d",&n,&m);
	FOR(i, 1, n) scanf("%s",s[i]);
	FOR(i, 1, m) scanf("%d",a+i), f[a[i]] = 1;
	len = strlen(s[a[1]]);
	FOR(i, 2, m)
	{
		x = strlen(s[a[i]]);
		if(x != len)
		{
			puts("No");
			return 0;
		}
	}
	for(i = 0; i < len; i ++)
	{
		for(j = 2; j <= m; j ++)
			if(s[a[j]][i] != s[a[1]][i])break;
		if(j > m)ans[i] = s[a[1]][i];
		else ans[i] = '?';
	}
	for(i = 1; i <= n; i ++)
		if(!f[i])
			if(strlen(s[i]) == len)
			{
				for(j = 0; j < len; j ++)
					if(ans[j] != s[i][j] && ans[j] != '?')break;
				if(j >= len)
				{
					puts("No");
					return 0;
				}
			}
	puts("Yes");
	puts(ans);
	return 0;
}