#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int n,msk,len,ar[111111],dist[444444],a[66],b[66],c[66],aa[66],bb[66],cc[66],tot[66];
pair<int,pair<int,int> > d[444444];
int ans,ansa[111111],ansb[111111],ansc[111111],pre[444444];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&ar[i]);
	}
	for (int i=0;i<(1<<6);i++)
	{
		queue<int> q;
		q.push(i);
		memset(dist,-1,sizeof(dist));
		dist[i]=0;
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			if (dist[x]>=2) break;
			for (int j=0;j<12;j++)
			{
				for (int k=j+1;k<12;k++)
				{
					int h=2*k-j;
					if (h>=12) continue;
					int nmsk=x^(1<<j)^(1<<k)^(1<<h);
					if (!~dist[nmsk])
					{
						if (dist[x]==1) 
						{
							if (nmsk%(1<<6)==0)
							{
								a[i]=j;b[i]=k;c[i]=h;
								aa[i]=d[x].first;bb[i]=d[x].second.first;cc[i]=d[x].second.second;
								tot[i]=nmsk>>6;
							}
						}
						else
						{
							dist[nmsk]=1;
							d[nmsk]=make_pair(j,make_pair(k,h));
							q.push(nmsk); 
						}
					}
				}
			}
		}
	}
	while(n>=17)
	{
		msk=0;
		for (int i=n;i>=n-5;i--)
		{
			msk|=(ar[i]<<(n-i));
		}
		ans++;ansa[ans]=n-a[msk];ansb[ans]=n-b[msk];ansc[ans]=n-c[msk];
		ans++;ansa[ans]=n-aa[msk];ansb[ans]=n-bb[msk];ansc[ans]=n-cc[msk];
		n-=6;
		for (int i=n;i>=n-5;i--)
		{
			if (tot[msk]&(1<<(n-i))) ar[i]^=1;
		}
	}
	msk=0;
	for (int i=1;i<=n;i++)
	{
		msk|=(ar[i]<<(i-1));
	}
	queue<int> q;
	q.push(0);
	memset(dist,-1,sizeof(dist));
	dist[0]=0; 
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for (int j=0;j<n;j++)
		{
			for (int k=j+1;k<n;k++)
			{
				int h=2*k-j;
				if (h>=n) continue;
				int nmsk=x^(1<<j)^(1<<k)^(1<<h);
				if (!~dist[nmsk])
				{
					dist[nmsk]=dist[x]+1;
					d[nmsk]=make_pair(j,make_pair(k,h));
					pre[nmsk]=x;
					q.push(nmsk); 
				}
			}
		}
	}
	if (!~dist[msk])
	{
		printf("NO\n");
		return 0;
	}
	while(msk)
	{
		ans++;ansa[ans]=d[msk].first+1;ansb[ans]=d[msk].second.first+1;ansc[ans]=d[msk].second.second+1;
		msk=pre[msk];
	}
	printf("YES\n%d\n",ans);
	for (int i=1;i<=ans;i++)
	{
		printf("%d %d %d\n",ansa[i],ansb[i],ansc[i]);
	}
	return 0;
}