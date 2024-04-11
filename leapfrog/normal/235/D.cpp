//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
struct edge{int to,nxt;}e[6005];int et,head[3005],f[3005][12],dep[3005];
int n,dg[3005],q[3005],hd,tl,ct,cl[3005];char nc[3005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et,dg[x]++;}
inline void dfs(int x,int fa,int cc)
{
	dep[x]=dep[fa]+1,cl[x]=cc,f[x][0]=fa;
	for(int i=1;i<12;i++) f[x][i]=f[f[x][i-1]][i-1];
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa&&nc[e[i].to]) dfs(e[i].to,x,cc);
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=11;~i;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	for(int i=11;~i;i--) if(f[x][i]^f[y][i]) x=f[x][i],y=f[y][i];
	return x^y?f[x][0]:x;
}
inline int dis(int x,int y) {return dep[x]+dep[y]-(dep[LCA(x,y)]<<1)+1;}
inline void topo()
{
	hd=tl=0;for(int i=1;i<=n;i++) if(dg[i]==1) q[++tl]=i,nc[i]=1;
	for(int x=q[++hd];hd<=tl;x=q[++hd]) for(int i=head[x];i;i=e[i].nxt)
		if(--dg[e[i].to]==1) q[++tl]=e[i].to,nc[e[i].to]=1;
	for(int i=1;i<=n;i++) if(!nc[i]) dfs(i,0,++ct);
}
int main()
{
	read(n);for(int i=1,x,y;i<=n;i++) read(x,y),adde(++x,++y),adde(y,x);
	topo();double rs=0;for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		if(cl[i]^cl[j])
		{
			int v=dep[i]+dep[j],a=abs(cl[i]-cl[j])-1,b=ct-2-a;
			rs+=1.0/(v+a)+1.0/(v+b)-1.0/(v+a+b);
		}
		else rs+=1.0/dis(i,j);
	return printf("%.10lf\n",rs),0;
}