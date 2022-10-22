#include<cstdio>
#include<queue>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define div(a) ((a)-(a)/2)
#define val(a) ((long long)div(len[a])*siz[a])
using namespace std;
const int N=1e5,M=3e6,INF=0x3fffffff;
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
	int next,to,dis,cost;
}e[2*N];
int T,n,hd[N],cnt,siz[N],len[N],cost[N],cnt1,cnt2;
long long s,f1[M],f2[M],ans;
struct cmp
{
	bool operator()(int a,int b)const{return val(a)<val(b);}
};
priority_queue<int,vector<int>,cmp> q1,q2;
void adline(int u,int v,int w,int c)
{
	e[cnt].to=v;
	e[cnt].dis=w;
	e[cnt].cost=c;
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
		cost[v]=e[i].cost;
		dfs(v,u);
		siz[u]+=siz[v];
	}
	if(!siz[u])siz[u]=1;
}
inline long long divide(int i)
{
	long long res=val(i);
	len[i]/=2;
	return res;
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
			int u,v,w,c;read(u);read(v);read(w);read(c);
			adline(--u,--v,w,c);adline(v,u,w,c);
		}
		dfs(0,0);
		s=-s;
		F(i,0,n)s+=(long long)len[i]*siz[i];
		while(!q1.empty())q1.pop();
		while(!q2.empty())q2.pop();
		F(i,1,n)if(cost[i]==1)q1.push(i);else q2.push(i);
		ans=INF;
		cnt1=cnt2=0;
		f1[0]=f2[0]=0;
		while(!q1.empty())
		{
			int a=q1.top();q1.pop();
			f1[cnt1+1]=divide(a)+f1[cnt1];
			++cnt1;
			if(len[a])q1.push(a);
		}
		while(!q2.empty())
		{
			int a=q2.top();q2.pop();
			f2[cnt2+1]=divide(a)+f2[cnt2];
			++cnt2;
			if(len[a])q2.push(a);
		}
		for(int i=0,j=cnt1;i<=cnt2;++i)
		{
			while(j&&f2[i]+f1[j-1]>=s)--j;
			if(f2[i]+f1[j]>=s)if(ans>2*i+j)ans=2*i+j;
		}
		printf("%d\n",ans);
	}
	return 0;
}