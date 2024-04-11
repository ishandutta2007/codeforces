#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int num[10010];
int main()
{
	int n,cnt;
	while(scanf("%d",&n) != EOF)
	{
		memset(num,0,sizeof(num));
		cnt = 0;
		for(int i = 1; i <= n; i ++) 
		{
			num[++ cnt] = 1;
			while(num[cnt] == num[cnt - 1])
			{
				num[cnt - 1] = num[cnt] + 1;
				cnt --;
			}
		}
		for(int i = 1; i <= cnt; i ++)
		{
			if(i == cnt) printf("%d\n",num[cnt]);
			else printf("%d ",num[i]);
		}
	}
	
	return 0;
}