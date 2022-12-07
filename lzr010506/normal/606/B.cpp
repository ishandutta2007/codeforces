#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m,y,x;
int e[550][550],ans[100010];
char s[100010];
int main()
{
	scanf("%d%d%d%d",&n,&m,&y,&x);
	scanf("%s",s);
	int len = strlen(s);
	ans[len] = n * m;
	for(int i = 0; i < len; i ++)
	{
		if(e[y][x] == 0)
		{
			e[y][x] = 1;
			ans[i] = 1;
			ans[len] --;
		}
		else ans[i] = 0;
		if(s[i]=='L')
		{
			if(x > 1) x --;
		}
		else 
			if(s[i]=='R')
			{
				if(x < m)x ++;
			}
			else 
				if(s[i]=='U')
				{
					if(y > 1)y --;
				}
				else
				{
					if(y < n)y ++;
				}
	}
	for(int i = 0; i <= len; i ++)
		printf("%d ",ans[i]);
	return 0;
}