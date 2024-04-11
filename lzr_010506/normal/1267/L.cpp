#include<bits/stdc++.h>
using namespace std;
char c[1000010], ans[1010][1010];
int main()
{
	int n, l, k;
	scanf("%d%d%d%s", &n, &l, &k, c + 1);
	sort(c + 1, c + n * l + 1);
	
	int pos = 1, now = 0;
	for(int i=1; i<=l; ++i)
	{
		for(int j=pos; j<=k; ++j)
		{ 
			++now;
			ans[j][i] = c[now];
			//printf("%d %d %c\n", j, i, c[now]);
			if(c[now] != c[now - 1]) pos = j;
		}
		if(pos == k)
		{
			for(int j=i+1; j<=l; ++j)
			{
				ans[k][j] = c[++now];
				//printf("%d %d %c.\n", k, j, c[now]);
			}
			break;
		}
	}
	
	for(int i=1; i<=l; ++i)
	for(int j=1; j<=n; ++j)
		if(!ans[j][i]) ans[j][i] = c[++now];
	
	for(int i=1; i<=n; ++i, printf("\n"))
	for(int j=1; j<=l; ++j)
		printf("%c", ans[i][j]);
}