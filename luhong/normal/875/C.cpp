#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
int h[201000],nxt[4010000],to[4010000],K=0;
int low[201000],cnt=0,id[201000],dfn[201000],in[201000],st[201000],top=0,dfs=0;
int d[201000],q[201000],H=0,T=0;
int ans[201000],u[4001000],v[4001000],op[201000],M;int n,m;
map<int,int> mp[201000];
int Ans[201000],tt=0;
void ins(int uu,int vv){nxt[++K]=h[uu];h[uu]=K;to[K]=vv;}
void tarjan(int x)
{
	low[x]=dfn[x]=++dfs;st[++top]=x;in[x]=1;
	for(int i=h[x];i;i=nxt[i])
	{
		if(!dfn[to[i]])
		{
			tarjan(to[i]);
			low[x]=min(low[x],low[to[i]]);
		}
		else if(in[to[i]]) low[x]=min(low[x],dfn[to[i]]);
	}
	if(dfn[x]==low[x])
	{
		++cnt;
		do{
			id[st[top]]=cnt;in[st[top]]=0;
		}while(st[top--]!=x);
	}
}
bool two_sat()
{
	for(int i=1;i<=2*m;i++)
	{
		if(!dfn[i])tarjan(i);
	}
	M=K;
	memset(h,0,sizeof(h)),K=0;
	for(int i=1;i<=2*m;i+=2)
	{
		if(id[i]==id[i+1])return 0;
		op[id[i]]=id[i+1];
		op[id[i+1]]=id[i];
	}
	for(int i=1;i<=M;i++)
	{
		int U=id[u[i]],V=id[v[i]];
		if(U==V)continue;
		if(!mp[V][U])ins(V,U),mp[V][U]=1,d[U]++;
	}
	memset(ans,-1,sizeof(ans));
	H=T=0;
	for(int i=1;i<=cnt;i++)if(!d[i])q[T++]=i;
	while(H<T)
	{
		int u=q[H++];if(ans[u]!=-1)continue;
		ans[u]=1;ans[op[u]]=0;
		for(int i=h[u];i;i=nxt[i])
			if(--d[to[i]]==0)q[T++]=to[i];
	}
	for(int i=1;i<=2*m;i+=2)
	{
		if(ans[id[i]]==1)Ans[++tt]=i+1>>1;
	}
	return 1;
}
int lst[101000],len,now[101000];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int k;scanf("%d",&k);
		for(int j=1;j<=k;j++)scanf("%d",&now[j]);
		if(i!=1)
		{
			int o;
			for(o=1;o<=min(len,k);o++)
			{
				if(now[o]!=lst[o])
				{
					if(now[o]<lst[o])ins(lst[o]*2,lst[o]*2-1),u[K]=lst[o]*2,v[K]=lst[o]*2-1,
									 ins(now[o]*2-1,now[o]*2),u[K]=now[o]*2-1,v[K]=now[o]*2;
					if(now[o]>lst[o])ins(lst[o]*2,now[o]*2),u[K]=lst[o]*2,v[K]=now[o]*2,
									 ins(now[o]*2-1,lst[o]*2-1),u[K]=now[o]*2-1,v[K]=lst[o]*2-1;
					break;
				}
			}
			if(o==min(len,k)+1)
			{
				if(o<=len)
				{
					return 0*puts("No");
				}
			}
		}
		len=k;for(int j=1;j<=k;j++)lst[j]=now[j];
	}
	if(!two_sat())puts("No");
	else
	{
		puts("Yes");
		printf("%d\n",tt);
		for(int i=1;i<=tt;i++)printf("%d ",Ans[i]);
	}
	return 0;
 }