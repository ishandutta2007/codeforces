//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,m,deg[1000005],qwq[1000005],fa[1000005],num[1000005];
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline void mrg(int x,int y) {int u=getf(x),v=getf(y);if(u^v) fa[u]=v;}
int main()
{
	read(n),read(m);int res=0;for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1,x,y;i<=m;i++) read(x),read(y),deg[x]++,deg[y]++,mrg(x,y),num[x]=num[y]=1;
	for(int i=1;i<=n;i++) qwq[getf(i)]+=deg[i]&1;
	int umi=!num[getf(1)];for(int i=1;i<=n;i++) if(getf(i)==i&&num[i]) umi++;
	if(umi==1) return printf("%d\n",qwq[getf(1)]>>1),0;else num[getf(1)]=1;
	for(int i=1;i<=n;i++) if(getf(i)==i&&num[i]) res+=qwq[i]>>1,res+=!qwq[i];
	return printf("%d\n",res),0;
}