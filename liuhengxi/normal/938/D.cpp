#include<cstdio>
#include<queue>
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
	long long dis;
}e[2*N];
struct node
{
	int id;
	long long dis;
	node(int a,long long b){id=a;dis=b;}
	bool operator<(node b)const{return b.dis<dis;}
};
int n,m,hd[N],cnt;
bool vis[N];
long long dis[N];
priority_queue<node> q;
void adline(int u,int v,long long w)
{
	e[cnt].to=v;
	e[cnt].dis=w;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
int main()
{
	read(n);read(m);
	F(i,0,n)hd[i]=-1;
	F(i,0,m)
	{
		int u,v;long long w;
		read(u);read(v);read(w);
		adline(--u,--v,w*=2);
		adline(v,u,w);
	}
	F(i,0,n)read(dis[i]);
	F(i,0,n)q.push(node(i,dis[i]));
	while(!q.empty())
	{
		int u=q.top().id;q.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to;
			if(dis[u]+e[i].dis<dis[v])
			{
				dis[v]=dis[u]+e[i].dis;
				q.push(node(v,dis[v]));
			}
		}
	}
	F(i,0,n)printf("%lld ",dis[i]);
	puts("");
	return 0;
}