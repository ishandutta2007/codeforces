#include <cstdio>
#include <iostream>
#define MN 101000

int pre[2][MN], suf[2][MN];
char s[MN];
int n, k;

int main()
{
	scanf("%d%d%s", &n, &k, s + 1);
	
	pre[0][0] = 0; pre[1][0] = 0;
	suf[0][n + 1] = n + 1; suf[1][n + 1] = n + 1;
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			pre[j][i] = pre[j][i - 1];
			if(s[i] - '0' == j) pre[j][i] = i;
		}
	}
	
	for(int i = n; i >= 1; i--)
	{
		for(int j = 0; j < 2; j++)
		{
			suf[j][i] = suf[j][i + 1];
			if(s[i] - '0' == j) suf[j][i] = i;
		}
	}
	
	bool ok1 = 0, ok2 = 0;
	for(int l = 1; l + k - 1 <= n; l++)
	{
		int r = l + k - 1;
		for(int j = 0; j < 2; j++)
		{
			if(pre[j][l - 1] == 0 && suf[j][r + 1] == n + 1) ok1 = 1;
			if(pre[j][l - 1] > 0 && suf[j][r + 1] <= n || pre[j][l - 1] - suf[j][1] >= k || pre[j][n] - suf[j][r + 1] >= k) ok2 = 1;
		}
	}
	if(ok1) puts("tokitsukaze");
	else if(!ok2) puts("quailty");
	else puts("once again");
}