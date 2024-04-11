#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+10;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int q,fa[N][22],logn,n=4,a=1,b=2,dep[N],ans=2;
inline int lca(int u,int v)
{
	int k=dep[u]-dep[v];
	if(k>0){for(int i=0;k;k>>=1,++i)if(k&1)u=fa[u][i];}
	else{k=-k;for(int i=0;k;k>>=1,++i)if(k&1)v=fa[v][i];}
	for(int i=logn;~i;--i)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return u!=v?fa[u][0]:u;
}
inline int dis(int u,int v){return dep[u]+dep[v]-(dep[lca(u,v)]<<1);}
int main()
{
	read(q);while((1<<logn)<(2*q+4))++logn;
	dep[1]=dep[2]=dep[3]=1;
	while(q--)
	{
		int u,t;read(u);--u;
		fa[n][0]=u;
		F(i,0,logn)fa[n][i+1]=fa[fa[n][i]][i];
		dep[n]=dep[u]+1;
		if((t=dis(a,n))>ans)ans=t,b=n;
		if((t=dis(n,b))>ans)ans=t,a=n;
		++n;
		fa[n][0]=u;
		F(i,0,logn)fa[n][i+1]=fa[fa[n][i]][i];
		dep[n]=dep[u]+1;
		if((t=dis(a,n))>ans)ans=t,b=n;
		if((t=dis(n,b))>ans)ans=t,a=n;
		++n;
		printf("%d\n",ans);
	}
	return 0;
}