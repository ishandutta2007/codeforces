#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct line
{
	int next,to;
}e[2*N];
int n,m,hd[N],cnt,q[N],qf,qr,f[N],k,p[N],t,c[N];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void bfs()
{
	F(i,0,n)f[i]=-1;
	f[q[qr++]=t]=0;
	while(qf<qr)
	{
		int u=q[qf++];
		for(int i=hd[u];~i;i=e[i].next)if(i&1)
		{
			int v=e[i].to;
			if(!~f[v])f[q[qr++]=v]=f[u]+1;
		}
	}
}
int main()
{
	int ans1=0,ans2=0;
	read(n);read(m);
	F(i,0,n)hd[i]=-1;
	F(i,0,m)
	{
		int u,v;read(u);read(v);
		adline(--u,--v);
		adline(v,u);
	}
	read(k);
	F(i,0,k)read(p[i]),--p[i];
	t=p[k-1];
	bfs();
	F(u,0,n)
	{
		for(int i=hd[u];~i;i=e[i].next)if((i&1)^1)
		{
			int v=e[i].to;
			if(f[v]==f[u]-1)++c[u];
		}
	}
	F(i,0,k-1)
	{
		if(f[p[i+1]]!=f[p[i]]-1)++ans1,++ans2;
		else if(c[p[i]]!=1)++ans2;
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}