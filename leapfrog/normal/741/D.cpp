//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
struct edge{int to,w,nxt;}e[1000005];int et,head[500005],rs[500005];
int n,dep[500005],sz[500005],ds[500005],F[(1<<22)+5],sn[500005];char ch[5];
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline void dfs0(int x,int fa)
{
	dep[x]=dep[fa]+1,sz[x]=1;
	for(int i=head[x];i;i=e[i].nxt)
	{
		ds[e[i].to]=ds[x]^(1<<e[i].w),dfs0(e[i].to,x),sz[x]+=sz[e[i].to];
		if(sz[e[i].to]>sz[sn[x]]) sn[x]=e[i].to;
	}
}
inline void baoli(int x,char tag)
{
	if(tag) F[ds[x]]=max(F[ds[x]],dep[x]);else F[ds[x]]=0;
	for(int i=head[x];i;i=e[i].nxt) baoli(e[i].to,tag);
}
inline int dfs1(int x,int rtd)
{
	//printf("@@ %d %d\n",x,rtd);
	int res=0;if(F[ds[x]]) res=max(res,F[ds[x]]+dep[x]-(rtd<<1));
	for(int i=0;i<22;i++) if(F[ds[x]^(1<<i)]) res=max(res,F[ds[x]^(1<<i)]+dep[x]-(rtd<<1));
	for(int i=head[x];i;i=e[i].nxt) res=max(res,dfs1(e[i].to,rtd));
	return res;
}
inline void dfs2(int x)
{
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to^sn[x]) dfs2(e[i].to),rs[x]=max(rs[e[i].to],rs[x]),baoli(e[i].to,0);
	if(sn[x]) dfs2(sn[x]),rs[x]=max(rs[x],rs[sn[x]]);
	if(F[ds[x]]) rs[x]=max(rs[x],F[ds[x]]-dep[x]);
	for(int i=0;i<22;i++) if(F[ds[x]^(1<<i)]) rs[x]=max(rs[x],F[ds[x]^(1<<i)]-dep[x]);
	F[ds[x]]=max(F[ds[x]],dep[x]);
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to^sn[x]) rs[x]=max(rs[x],dfs1(e[i].to,dep[x])),baoli(e[i].to,1);
}
int main()
{
	read(n);for(int i=2,f;i<=n;i++) read(f),scanf("%s",ch),adde(f,i,*ch-'a');
	dep[0]=-1,dfs0(1,0),dfs2(1);for(int i=1;i<=n;i++) printf("%d%c",rs[i],i==n?'\n':' ');
	return 0;
}