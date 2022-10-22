#include<cstdio>
#include<queue>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
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
int n,m,hd[N],cnt,siz[N],label[N],deg[N];
priority_queue<int> q;
inline void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
int main()
{
	read(n);read(m);
	F(i,0,n)hd[i]=-1;
	F(i,0,m)
	{
		int u,v;read(u);read(v);
		adline(--v,--u);
		++deg[u];
	}
	F(i,0,n)if(deg[i]==0)q.push(i);
	for(int i=n;i;--i)
	{
		int u=q.top();q.pop();
		label[u]=i;
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to;
			if(!--deg[v])q.push(v);
		}
	}
	F(i,0,n)printf("%d ",label[i]);
	puts("");
	return 0;
}