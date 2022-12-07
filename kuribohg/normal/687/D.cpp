#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,Q;
inline int get()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
}
struct Edge
{
	int x,y,w,id;
	friend bool operator<(const Edge &p,const Edge &q)
	{
		return p.w>q.w;
	}
}E[1000*500];
int fa[2010];
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
inline void uni(int x,int y)
{
	fa[find(x)]=find(y);
}
int main()
{
	n=get(),m=get(),Q=get();
	for(int i=1;i<=m;i++) E[i].x=get(),E[i].y=get(),E[i].w=get(),E[i].id=i;
	sort(E+1,E+m+1);
	while(Q--)
	{
		int l,r;
		l=get(),r=get();
		for(int i=1;i<=n+n;i++) fa[i]=i;
		int ans=-1;
		for(int i=1;i<=m;i++)
			if(E[i].id>=l&&E[i].id<=r)
			{
				if(find(E[i].x)==find(E[i].y)) {ans=E[i].w;break;}
				uni(E[i].x,E[i].y+n);
				uni(E[i].x+n,E[i].y);
			}
		printf("%d\n",ans);
	}
	return 0;
}