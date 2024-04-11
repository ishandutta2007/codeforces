#include<iostream>
#include<cstdio>
#include<vector> 
#include<cstring>
#include<algorithm>
using namespace std;
int sum[9000000],root[200001],ls[9000000],rs[9000000],tot=0;int val[200001],n,m;
int h[200001],nxt[400001],to[400001],K=0;
int top[200001],size[200001],son[200001],fa[200001],dep[200001];
vector<int> c[200001];int ans[20],cnt=0; 
void ins(int u,int v){nxt[++K]=h[u];h[u]=K;to[K]=v;}
int build(int l,int r)
{
	if(l==r){return ++tot;}int mid=l+r>>1,kk=++tot;
	ls[kk]=build(l,mid);rs[kk]=build(mid+1,r);
	return kk;
}
int modify(int X1,int X2,int l,int r,int k)
{
	int kk;if(X2!=X1&&X2)kk=X2;else kk=++tot;
	if(l==r&&l==k){sum[kk]=sum[X1]+1;return kk;}
	int mid=l+r>>1;//cout<<X1<<" "<<X2<<" "<<l<<" "<<r<<" "<<k<<" "<<mid<<endl;
	if(k<=mid){ls[kk]=modify(ls[X1],ls[X2],l,mid,k);if(!rs[kk])rs[kk]=rs[X1];}
	else {rs[kk]=modify(rs[X1],rs[X2],mid+1,r,k);if(!ls[kk])ls[kk]=ls[X1];}
	sum[kk]=sum[ls[kk]]+sum[rs[kk]];
	return kk;
}
void print(int x,int l,int r)
{
	cout<<x<<" "<<ls[x]<<" "<<rs[x]<<endl;if(l==r)return;
	
	int mid=l+r>>1;print(ls[x],l,mid);print(rs[x],mid+1,r);
}
//             u     v      lca    fa lca
void query(int X1,int X2,int X3,int X4,int l,int r,int rank)
{
	if(sum[X1]+sum[X2]-sum[X3]-sum[X4]==0)return;
	if(l==r){ans[++cnt]=l;return;}int Rank=sum[ls[X1]]+sum[ls[X2]]-sum[ls[X3]]-sum[ls[X4]];int mid=l+r>>1;//cout<<l<<" "<<r<<" "<<Rank<<" "<<rank<<endl;
	if(Rank>=rank){query(ls[X1],ls[X2],ls[X3],ls[X4],l,mid,rank);}
	else {query(rs[X1],rs[X2],rs[X3],rs[X4],mid+1,r,rank-Rank);query(ls[X1],ls[X2],ls[X3],ls[X4],l,mid,1999999999);}
}
void dfs1(int x,int f,int d)
{
	fa[x]=f;dep[x]=d;size[x]=1;
	ls[++tot]=ls[root[f]];rs[tot]=rs[root[f]];root[x]=tot;sum[tot]=sum[root[f]];
	for(int i=0;i<c[x].size();i++)root[x]=modify(root[f],root[x],1,m,c[x][i]);
	for(int i=h[x];i;i=nxt[i])
		if(to[i]!=f)
		{
			dfs1(to[i],x,d+1),size[x]+=size[to[i]];
			if(size[to[i]]>size[son[x]])son[x]=to[i];
		}
}
void dfs2(int x,int tp)
{
	top[x]=tp;if(son[x])dfs2(son[x],tp);
	for(int i=h[x];i;i=nxt[i])if(to[i]!=fa[x]&&to[i]!=son[x])dfs2(to[i],to[i]);
}
int lca(int u,int v)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]>dep[top[v]])u=fa[top[u]];else v=fa[top[v]];
	}
	if(dep[u]<dep[v])return u;return v;
}
int main()
{
	int q;scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<n;i++){int u,v;scanf("%d%d",&u,&v);ins(u,v);ins(v,u);}
	for(int i=1;i<=m;i++)scanf("%d",&val[i]),c[val[i]].push_back(i);
	root[0]=build(1,m);dfs1(1,0,1);dfs2(1,1);
	for(int i=1;i<=q;i++)
	{
		cnt=0;
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		int l=lca(x,y);query(root[x],root[y],root[l],root[fa[l]],1,m,z);
		sort(ans+1,ans+cnt+1);
		printf("%d",cnt);
		for(int j=1;j<=cnt;j++)printf(" %d",ans[j]);puts("");
	}
	return 0;
}