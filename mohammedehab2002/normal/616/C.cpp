#include <iostream>
#include <set>
using namespace std;
int n,m;
char arr[1005][1005],ans[1005][1005];
pair<int,int> o[1005][1005];
int siz[1005][1005];
bool vis[1005][1005];
int flood(int i,int x,int oi,int ox)
{
	if (i<0 || x<0 || i>=n || x>=m)
	return 0;
	if (vis[i][x] || arr[i][x]=='*')
	return 0;
	vis[i][x]=1;
	o[i][x]=make_pair(oi,ox);
	int ans=1;
	ans+=flood(i+1,x,oi,ox);
	ans+=flood(i-1,x,oi,ox);
	ans+=flood(i,x+1,oi,ox);
	ans+=flood(i,x-1,oi,ox);
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	{
		getchar();
		for (int x=0;x<m;x++)
		arr[i][x]=getchar();
	}
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<m;x++)
		{
			if (!vis[i][x] && arr[i][x]=='.')
			siz[i][x]=flood(i,x,i,x);
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<m;x++)
		{
			ans[i][x]=arr[i][x];
			if (arr[i][x]=='*')
			{
				set<pair<int,int> > tmp;
				if (i)
				{
					if (arr[i-1][x]=='.')
					tmp.insert(o[i-1][x]);
				}
				if (i<n-1)
				{
					if (arr[i+1][x]=='.')
					tmp.insert(o[i+1][x]);
				}
				if (x<m-1)
				{
					if (arr[i][x+1]=='.')
					tmp.insert(o[i][x+1]);
				}
				if (x)
				{
					if (arr[i][x-1]=='.')
					tmp.insert(o[i][x-1]);
				}
				int a=0;
				for (set<pair<int,int> >::iterator it=tmp.begin();it!=tmp.end();it++)
				a+=siz[(*it).first][(*it).second];
				ans[i][x]=((a+1)%10)+'0';
			}
		}
		puts(ans[i]);
	}
}