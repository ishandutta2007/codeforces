#include<cstdio>
#include<queue>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define div(a) ((a)-(a)/2)
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
	int next,to,dis;
}e[2*N];
int T,n,hd[N],cnt,siz[N],len[N];
long long s;
struct cmp
{
	bool operator()(int a,int b)const
	{return (long long)div(len[a])*siz[a]<(long long)div(len[b])*siz[b];}
};
priority_queue<int,vector<int>,cmp> q;
void adline(int u,int v,int w)
{
	e[cnt].to=v;
	e[cnt].dis=w;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u,int fa)
{
	siz[u]=0;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa)continue;
		len[v]=e[i].dis;
		dfs(v,u);
		siz[u]+=siz[v];
	}
	if(!siz[u])siz[u]=1;
}
int main()
{
	read(T);
	while(T--)
	{
		int ans=0;
		read(n);read(s);
		F(i,0,n)hd[i]=-1;
		cnt=0;
		F(i,0,n-1)
		{
			int u,v,w;read(u);read(v);read(w);
			adline(--u,--v,w);adline(v,u,w);
		}
		dfs(0,0);
		F(i,0,n)s-=(long long)len[i]*siz[i];
		while(!q.empty())q.pop();
		F(i,0,n)q.push(i);
		while(s<0&&!q.empty())
		{
			int i=q.top();q.pop();
			++ans;
			s+=(long long)div(len[i])*siz[i];
			len[i]/=2;
			if(len[i])q.push(i);
		}
		printf("%d\n",ans);
	}
	return 0;
}