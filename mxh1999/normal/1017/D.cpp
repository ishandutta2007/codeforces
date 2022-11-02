#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > b[10010];
pair<int,int> que[10010];
int a[10010];
int anss[500010];
int w[100];
int W[10010];
int n,m,q;
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	int all=1<<n;
	for (int i=0;i<all;i++)
		for (int j=1;j<=n;j++)
			if ((i&(1<<(n-j)))==0)	W[i]+=w[j];
	for (int i=1;i<=m;i++)
	{
		int x=0;
		for (int j=1;j<=n;j++)
		{
			char ch=getchar();
			while (ch!='0' && ch!='1')	ch=getchar();
			x=x*2+ch-'0';
		}
		a[x]++;
	}
	for (int i=1;i<=q;i++)
	{
		int x=0;
		for (int j=1;j<=n;j++)
		{
			char ch=getchar();
			while (ch!='0' && ch!='1')	ch=getchar();
			x=x*2+ch-'0';
		}
		int t;
		scanf("%d",&t);
		b[x].push_back(make_pair(t,i));
	}
	for (int i=0;i<all;i++)
	if (!b[i].empty())
	{
		sort(b[i].begin(),b[i].end());
		int cnt=0;
		for (int j=0;j<all;j++)
		if (a[j])
		{
			cnt++;
			que[cnt]=make_pair(W[j^i],a[j]);
		}
		sort(que+1,que+cnt+1);
		int now=1;
		int ans=0;
		for (int j=0;j<b[i].size();j++)
		{
			while (now<=cnt && que[now].first<=b[i][j].first)
			{
				ans+=que[now].second;
				now++;
			}
			anss[b[i][j].second]=ans;
		}
	}
	for (int i=1;i<=q;i++)
		printf("%d\n",anss[i]);
	return 0;
}