#include<cstdio>
#include<vector>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5e5+5,INF=N-1;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
struct line
{
	int next,to,col;
}e[2*N];
struct fake_queue
{
	vector<int> q[N];
	int pt;
	void push(int u,int dis){q[dis].push_back(u);}
	bool empty(){while(pt<N&&q[pt].empty())++pt;return pt==N;}
	int front(){while(pt<N&&q[pt].empty())++pt;return q[pt].back();}
	void pop(){while(pt<N&&q[pt].empty())++pt;q[pt].pop_back();}
}fq;
int n,m,hd[N],cnt,f[2][N],g[N],col[N];
bool vis[N];
void adline(int u,int v,int c)
{
	e[cnt].to=v;
	e[cnt].col=c;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
int main()
{
	read(n,m);
	F(i,0,n)hd[i]=-1;
	F(i,0,m)
	{
		int u,v,c;--read(u),--read(v),read(c);
		adline(v,u,c);
	}
	F(i,0,n-1)f[0][i]=f[1][i]=g[i]=INF;
	F(i,0,n)fq.push(i,g[i]);
	while(!fq.empty())
	{
		int u=fq.front();fq.pop();
		if(vis[u])continue;
		vis[u]=true;col[u]=f[0][u]<f[1][u];
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to;
			f[e[i].col][v]=min(f[e[i].col][v],g[u]+1);
			g[v]=max(f[0][v],f[1][v]);
			fq.push(v,g[v]);
		}
	}
	printf("%d\n",g[0]==INF?-1:g[0]);
	F(i,0,n)printf("%d",col[i]);
	puts("");
	return 0;
}