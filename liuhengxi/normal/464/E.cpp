#include<cstdio>
#include<algorithm>
#include<queue>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
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
constexpr int N=1e5+25,MOD=1001081017,bas[2]={8181891,89189},MOD2=1000000007;
int pw[N][2],sum[N][2];
namespace seg
{
	constexpr int N=2e7+5;
	int s[N][2],ls[N],rs[N],ind;
	int clear(int p,int l,int r,int x,int y)
	{
		if(!p||y<=l||r<=x)return p;
		if(x<=l&&r<=y)return 0;
		int mid=(l+r)>>1,q=++ind;
		ls[q]=clear(ls[p],l,mid,x,y);
		rs[q]=clear(rs[p],mid,r,x,y);
		s[q][0]=(int)((s[ls[q]][0]*(long long)pw[r-mid][0]+s[rs[q]][0])%MOD);
		s[q][1]=(int)((s[ls[q]][1]*(long long)pw[r-mid][1]+s[rs[q]][1])%MOD);
		return q;
	}
	int set1(int p,int l,int r,int x)
	{
		int q=++ind;
		if(r-l==1)return s[q][1]=s[q][0]=1,q;
		int mid=(l+r)>>1;
		if(x<mid)ls[q]=set1(ls[p],l,mid,x),rs[q]=rs[p];
		else ls[q]=ls[p],rs[q]=set1(rs[p],mid,r,x);
		s[q][0]=(int)((s[ls[q]][0]*(long long)pw[r-mid][0]+s[rs[q]][0])%MOD);
		s[q][1]=(int)((s[ls[q]][1]*(long long)pw[r-mid][1]+s[rs[q]][1])%MOD);
		return q;
	}
	int count(int p,int l,int r,int x)
	{
		if(r-l==1)return s[p][0];
		if(x>=r&&s[p][0]==sum[r-l][0]&&s[p][1]==sum[r-l][1])return r-l;
		int mid=(l+r)>>1;
		if(x<=mid)return count(ls[p],l,mid,x);
		int rf=min(r,x)-mid,rt=count(rs[p],mid,r,x);
		if(rf!=rt)return rt;
		return count(ls[p],l,mid,x)+rf;
	}
	int comp(int p,int q,int l,int r)
	{
		if(s[p][0]==s[q][0]&&s[p][1]==s[q][1])return 0;
		if(r-l==1)return s[p][0]-s[q][0];
		int mid=(l+r)>>1;
		int ans=comp(ls[p],ls[q],l,mid);
		if(ans)return ans;
		return comp(rs[p],rs[q],mid,r);
	}
}
using seg::clear;using seg::set1;using seg::count;using seg::comp;
struct line
{
	int next,to,dis;
}e[N<<1];
int k;
struct nodedis
{
	int node,rt;
	friend bool operator<(nodedis b,nodedis a){return comp(a.rt,b.rt,0,k)<0;}
};
int n,m,s,t,hd[N],cnt,dis[N],inf,pre[N],ab[N],ans,sta[N],top;
bool vis[N];
priority_queue<nodedis> q;
void addline(int u,int v,int w)
{
	e[cnt].to=v;
	e[cnt].dis=w;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void expand(int p,int l,int r)
{
	if(r-l==1)return void(ab[l]=seg::s[p][0]);
	int mid=(l+r)>>1;
	expand(seg::ls[p],l,mid);expand(seg::rs[p],mid,r);
}
int main()
{
	F(i,pw[0][1]=pw[0][0]=1,N)pw[i][0]=(int)((long long)pw[i-1][0]*bas[0]%MOD),pw[i][1]=(int)((long long)pw[i-1][1]*bas[1]%MOD);
	F(i,0,N-1)
	{
		((sum[i+1][0]=sum[i][0]+pw[i][0])>=MOD)&&(sum[i+1][0]-=MOD);
		((sum[i+1][1]=sum[i][1]+pw[i][1])>=MOD)&&(sum[i+1][1]-=MOD);
	}
	read(n,m);
	F(i,0,n)hd[i]=-1;
	k=20;
	F(i,0,m)
	{
		int u,v,w;read(u,v,w);--u,--v;
		addline(u,v,w);addline(v,u,w);
		k=max(k,w+20);
	}
	read(s,t);--s,--t;
	inf=set1(1,0,k,0);
	F(i,0,n)dis[i]=inf;
	dis[s]=0;
	q.push({s,0});
	while(!q.empty())
	{
		int u=q.top().node;q.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to,w=e[i].dis,x=dis[u];
			if(vis[v])continue;
			int r=k-w,l=r-count(x,0,k,r)-1;
			x=clear(x,0,k,l,r);
			x=set1(x,0,k,l);
			if(comp(x,dis[v],0,k)<0)dis[v]=x,q.push({v,x}),pre[v]=u;
		}
	}
	expand(dis[t],0,k);
	if(ab[0])return puts("-1"),0;
	F(i,0,k)(ans<<=1)^=ab[i],(ans>=MOD2)&&(ans-=MOD2);
	printf("%d\n",ans);
	while(t!=s)sta[top++]=t,t=pre[t];
	sta[top++]=t;
	printf("%d\n",top);
	while(top)printf("%d ",sta[--top]+1);
	puts("");
	return 0;
}