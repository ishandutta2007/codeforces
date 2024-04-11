#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;
int n,k;
int l[100];
char s[100];
char d[100][100];
int g[100];
int j=0,q;
int main()
{
	scanf("%d %d",&n,&k);
	l[0]=1;
	int u=1;
	for(int i=0;i<n;i++)
	{
		g[i]=9;
		d[i][0]='A';
		for(int j=1;j<9;j++) d[i][j]='a';
	}
	for(int i=0;i<n-k+1;i++)
	{
		scanf("%s",s);
		if(s[0]=='N')
		{
			j=0;
			while(l[i+j+1]!=0) j++;
			l[i+j+1]=l[i];
			g[i+j+1]=g[i];
			for(int p=0;p<9;p++)
			{
				d[i+j+1][p]=d[i][p];
			}
		}
		else
		{
			j=i;
			q=0;
			while(l[j]!=0) j++;
			while(j<i+k)
			{
				l[j]=u;
				for(int p=0;p<u;p++)
				{
					q=1;
					if(d[j][q]=='z') q++;
					d[j][q]++;
				}
				u++;
				j++;
			}
		}
		/*for(j=0;j<n;j++)
		{
			printf("%s ",d[j]);
		}
		printf("\n");*/
	}
	for(j=0;j<n;j++)
	{
		printf("%s ",d[j]);
	}
	return 0;
}