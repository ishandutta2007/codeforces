#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int a[1111111],n,c,x,y,pos,l,r,cnt;
vector<int> g[555555];
int main()
{
	scanf("%d%d",&n,&c);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		for (int j=1;j<=x;j++)
		{
			scanf("%d",&y);
			g[i].push_back(y); 
		}
	}
	for (int i=1;i<n;i++)
	{
		pos=-1;
		for (int j=0;j<g[i].size() && j<g[i+1].size();j++)
		{
			if (g[i][j]!=g[i+1][j]) 
			{
				pos=j;
				break;
			}
		}
		if (!~pos)
		{
			if (g[i].size()>g[i+1].size()) 
			{
				printf("-1\n");
				return 0;
			}
			continue;
		}
		cnt++;
		x=g[i][pos];y=g[i+1][pos];
		l=(c-x+1)%c;r=(c-y+1)%c;
		if (l>r) swap(l,r);
		r--;
		if (x<y)
		{
			if (!l)
			{
				a[r+1]--;a[l]++;
			}
			else
			{
				a[r+1]++;a[0]++;a[l]--;
			}
		}
		else
		{
			if (!l)
			{
				a[r+1]++;
			}
			else
			{
				a[r+1]--;a[l]++;
			}
		}
	}
	for (int i=1;i<c;i++) a[i]+=a[i-1];
	for (int i=0;i<c;i++)
	{
		if (a[i]==cnt) 
		{
			printf("%d\n",i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}