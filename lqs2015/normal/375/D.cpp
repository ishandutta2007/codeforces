#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int md=333;
int n,m,c[111111],buc[111111],st[111111],en[111111],cnt,xx,yy;
int ans[111111],x[111111],y[111111],num[111111],col[111111],id,cl,cr;
pair<pair<int,int>,int> ff[111111];
vector<int> g[111111];
void dfs(int i,int fa)
{
	st[i]=++cnt;
	buc[cnt]=c[i];
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to!=fa) dfs(to,i);
	}
	en[i]=cnt;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&xx,&yy);
		g[xx].push_back(yy);
		g[yy].push_back(xx);
	}
	dfs(1,0);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		ff[i]=make_pair(make_pair(st[x[i]]/md,en[x[i]]),i);
	}
	sort(ff+1,ff+m+1);
	cl=1;
	for (int i=1;i<=m;i++)
	{
		xx=x[ff[i].second];yy=y[ff[i].second];id=ff[i].second;
		while(cr<en[xx])
		{
			cr++;
			col[buc[cr]]++;
			num[col[buc[cr]]]++;
		}
		while(cl>st[xx])
		{
			cl--;
			col[buc[cl]]++;
			num[col[buc[cl]]]++;
		}
		while(cr>en[xx])
		{
			num[col[buc[cr]]]--;
			col[buc[cr]]--;
			cr--;
		}
		while(cl<st[xx])
		{
			num[col[buc[cl]]]--;
			col[buc[cl]]--;
			cl++;
		}
		ans[id]=num[yy];
	}
	for (int i=1;i<=m;i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}