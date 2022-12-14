#include<iostream>
#include<cstdio>
using namespace std;
int n,a[333333],p[333333];
int l[9999999],r[9999999],sz[9999999],t,pos,cnt,ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}
	cnt=1;
	for (int i=1;i<=n;i++)
	{
		pos=1;sz[1]++;
		for (int j=29;j>=0;j--)
		{
			if (p[i]&(1<<j))
			{
				if (!r[pos]) 
				{
					r[pos]=++cnt;
					pos=cnt;
					sz[pos]++;
				}
				else 
				{
					pos=r[pos];
					sz[pos]++;
				}
			}
			else
			{
				if (!l[pos]) 
				{
					l[pos]=++cnt;
					pos=cnt;
					sz[pos]++;
				}
				else 
				{
					pos=l[pos];
					sz[pos]++;
				}
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		pos=1;ans=0;sz[1]--;
		for (int j=29;j>=0;j--)
		{
			if (!(a[i]&(1<<j)))
			{
				if (l[pos] && sz[l[pos]]) 
				{
					pos=l[pos];
					sz[pos]--;
				}
				else
				{
					pos=r[pos];
					ans|=(1<<j);
					sz[pos]--;
				}
			}
			else
			{
				if (r[pos] && sz[r[pos]]) 
				{
					pos=r[pos];
					sz[pos]--;
				}
				else
				{
					pos=l[pos];
					ans|=(1<<j);
					sz[pos]--;
				}
			}
		}
		printf("%d ",ans);
	}
	printf("\n");
	return 0;
}