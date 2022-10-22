#include<cstdio>
#include<queue>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
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
	int next,to;
}e[2*N];
int n,h[N],d,hd[N],cnt,deg[N];
long long ans;
struct cmp{bool operator()(int a,int b){return h[a]>h[b];}};
priority_queue<int,vector<int>,cmp> q;
inline void adline(int u,int v){e[cnt].to=v;e[cnt].next=hd[u];hd[u]=cnt++;}
inline void adline2(int u,int v){adline(u,v);adline(v,u);}
int main()
{
	F(i,0,read(n))read(h[i]);
	F(i,0,n)hd[i]=-1;
	F(i,0,n-1)
	{
		int u,v;--read(u),--read(v);
		adline2(u,v);++deg[u],++deg[v];
	}
	F(i,0,n)if(deg[i]==1)q.push(i);
	while(!q.empty())
	{
		int u=q.top();q.pop();
		if(h[u]>d)ans+=(h[u]-d)*(q.size()+1ll+!q.size()),d=h[u];
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to;if(--deg[v]==1)q.push(v);
		}
	}
	printf("%lld\n",ans);
	return 0;
}