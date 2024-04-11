#include<bits/stdc++.h>
using namespace std;
int n,fa[2][200005],siz[2][200005];long long r;
inline int getf(int id,int x) {return x==fa[id][x]?x:fa[id][x]=getf(id,fa[id][x]);}
inline void mrg(int id,int x,int y)
{
	if(getf(id,x)!=getf(id,y)) siz[id][getf(id,y)]+=siz[id][getf(id,x)],fa[id][getf(id,x)]=getf(id,y);
}
int main()
{
	scanf("%d",&n),r=0;
	for(int i=1;i<=n;i++) fa[0][i]=fa[1][i]=i,siz[0][i]=siz[1][i]=1;
	for(int i=1,x,y,w;i<n;i++) scanf("%d%d%d",&x,&y,&w),mrg(w,x,y);
	for(int i=1;i<=n;i++) r+=1ll*siz[0][getf(0,i)]*siz[1][getf(1,i)]-1;
	return printf("%lld\n",r),0;
}