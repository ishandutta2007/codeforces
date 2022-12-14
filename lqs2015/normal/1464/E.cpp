#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,maxn=512;
int n,m,x,y,sg[111111],ord[111111],deg[111111],cnt,used[111111],pos,mat[555][555],iv,lst,ans[555],u[1111111];
vector<int> g[111111];
queue<int> q;
void topo()
{
	for (int i=1;i<=n;i++)
	{
		if (!deg[i]) q.push(i);
	}
	while(!q.empty())
	{
		int x=q.front();q.pop();ord[++cnt]=x;
		for (int i=0;i<g[x].size();i++)
		{
			int to=g[x][i];
			if (!--deg[to]) q.push(to);
		}
	}
}
int binpow(int a,int t)
{
	int res=1,p=a;
	for (int i=t;i;i>>=1)
	{
		if (i&1) res=1ll*res*p%mod;
		p=1ll*p*p%mod;
	}
	return res;
}
void add(int &x,int y)
{
	x+=y;
	if (x>=mod) x-=mod;
}
void gauss()
{
	for (int i=0;i<512;i++)
	{
		pos=-1;
		for (int j=i;j<512;j++)
		{
			if (mat[j][i]) 
			{
				pos=j;
				break;
			}
		}
		if (pos==-1) continue;
		for (int j=0;j<=512;j++) swap(mat[pos][j],mat[i][j]);
		for (int j=i+1;j<512;j++)
		{
			int coef=-1ll*mat[j][i]*binpow(mat[i][i],mod-2)%mod;
			for (int k=i;k<=512;k++)
			{
				mat[j][k]=(1ll*mat[i][k]*coef+mat[j][k])%mod;
			}
		}
	}
	for (int i=511;i>=0;i--)
	{
		lst=mat[i][512];
		for (int j=511;j>i;j--) lst=(-1ll*mat[i][j]*ans[j]+lst)%mod;
		ans[i]=1ll*lst*binpow(mat[i][i],mod-2)%mod;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		deg[y]++;
	}
	topo();
	for (int i=n;i>=1;i--)
	{
		for (int j=0;j<g[ord[i]].size();j++) u[sg[g[ord[i]][j]]]=1;
		pos=0;
		while(u[pos]) pos++;
		sg[ord[i]]=pos;
		for (int j=0;j<g[ord[i]].size();j++) u[sg[g[ord[i]][j]]]=0;
	}
	iv=mat[0][512]=binpow(n+1,mod-2);
	for (int i=0;i<512;i++)
	{
		mat[i][i]=1;
		for (int j=1;j<=n;j++)
		{
			add(mat[i][i^sg[j]],mod-iv);
		}
	}
	gauss();
	printf("%d\n",(mod+1-ans[0])%mod);
	return 0;
}