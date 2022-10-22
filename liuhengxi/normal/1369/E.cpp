#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,M=2e5+5;
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
}e[2*M];
int n,m,w[N],hd[N],cnt,q[N],qf,qr,ans[M],tot;
bool vis[N];
inline void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
int main()
{
	read(n);read(m);
	F(i,0,n)read(w[i]);
	F(i,0,n)hd[i]=-1;
	F(i,0,m)
	{
		int u,v;read(u);read(v);
		adline(--u,--v);adline(v,u);
		--w[u],--w[v];
	}
	F(i,0,n)if(w[i]>=0)q[qr++]=i;
	while(qf<qr)
	{
		int u=q[qf++];
		vis[u]=true;
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to;if(vis[v])continue;
			ans[tot++]=i>>1;
			++w[v];
			if(w[v]==0)q[qr++]=v;
		}
	}
	if(qr!=n)puts("DEAD");
	else
	{
		puts("ALIVE");
		while(tot)printf("%d ",ans[--tot]+1);
		puts("");
	}
	return 0;
}