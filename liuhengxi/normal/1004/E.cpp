#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,INF=0x3fffffff;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
struct line
{
	int next,to,dis;
}e[2*N];
int n,k,hd[N],cnt,x,y,dep[N],fa[N],pos[N],ch[N],len,q[N],qf,qr,pre[N],suf[N],ans;
bool on[N];
void adline(int u,int v,int w)
{
	e[cnt].to=v;
	e[cnt].dis=w;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs1(int u,int fa)
{
	::fa[u]=fa;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dep[v]=dep[u]+e[i].dis;
		dfs1(v,u);
	}
}
void dfs2(int u,int fa)
{
	dep[u]=0;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(on[v]||v==fa)continue;
		dfs2(v,u);
		dep[u]=max(dep[u],dep[v]+e[i].dis);
	}
}
int main()
{
	read(n,k);
	F(i,0,n)hd[i]=-1;
	F(i,0,n-1)
	{
		int u,v,w;--read(u);--read(v);read(w);
		adline(u,v,w);adline(v,u,w);
	}
	dfs1(0,0);
	F(i,0,n)if(dep[i]>dep[x])x=i;
	dfs1(x,x);
	::fa[x]=-1;
	F(i,0,n)if(dep[i]>dep[y])y=i;
	for(int u=y;~u;u=fa[u])on[ch[len++]=u]=true;
	F(i,0,len/2)swap(ch[i],ch[len-1-i]);
	F(i,0,n)pos[i]=dep[ch[i]];
	F(i,0,n)if(on[i])dfs2(i,i);
	F(i,0,n)ch[i]=dep[ch[i]];
	if(k>=len)F(i,0,len)ans=max(ans,ch[i]);
	else
	{
		pre[0]=ch[0];
		F(i,1,len)pre[i]=max(pre[i-1]+pos[i]-pos[i-1],ch[i]);
		for(int i=len;~--i;)suf[i]=max(suf[i+1]+pos[i+1]-pos[i],ch[i]);
		ans=INF;
		for(int i=0;i<len;++i)
		{
			while(qf<qr&&ch[q[qr-1]]<ch[i])--qr;
			while(qf<qr&&q[qf]<=i-k)++qf;
			q[qr++]=i;
			ans=min(ans,max(ch[q[qf]],max(pre[max(i-k+1,0)],suf[i])));
		}
	}
	printf("%d\n",ans);
	return 0;
}