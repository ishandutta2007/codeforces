#include<bits/stdc++.h>

using namespace std;

vector<int> a[200005];

int d[200005];
bool vis[200005];
int i,j,k,l,m,n;
long long int ans;

int min(int x,int y)
{
	return x<y?x:y;
}

long long int dfs(int x)
{
	int ii,o;
	long long int q,t;
	vis[x]=true;t=0;
	for(ii=0;ii<a[x].size();ii++)
	{
		o=a[x][ii];
		if(vis[o])continue;
		q=dfs(o);
		t+=q;q=min(m-q,q);
		ans+=q;
	}
	return t+d[x];
}

int main()
{
	scanf("%d%d",&n,&m);
	memset(a,0,sizeof(a));
	m*=2;
	memset(d,0,sizeof(d));
	for(i=1;i<=m;i++)
	{
		scanf("%d",&l);
		d[l]++;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d %d",&k,&l);
		a[k].push_back(l);
		a[l].push_back(k);
	}
	memset(vis,0,sizeof(vis));
	ans=0;l=dfs(1);
	printf("%lld",ans);
	return 0;
}