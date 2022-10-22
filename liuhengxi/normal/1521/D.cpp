#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
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
int tt,n,hd[N],cnt,f[N],a1[N],a2[N],a3[2*N],k,kk,last[N],deg[N],ff[N];
bool cut[N];
int find(int x){return ff[x]==x?x:ff[x]=find(ff[x]);}
inline void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u,int fa)
{
	int c=0;f[u]=fa;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dfs(v,u);
		if(!cut[v])++c;
	}
	if(u&&c>=2)cut[u]=true;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		if(!cut[v]&&c>2)--c,cut[v]=true;
	}
}
int main()
{
	read(tt);
	while(tt--)
	{
		F(i,cnt=0,read(n))hd[i]=-1;
		F(i,0,n-1)
		{
			int u,v;--read(u),--read(v);
			adline(u,v);adline(v,u);
		}
		F(i,0,n)cut[i]=false;
		dfs(0,0);
		F(i,0,n)deg[i]=0,ff[i]=i,last[i]=-1;
		k=0;
		F(i,1,n)if(cut[i])a1[k]=i,a2[k++]=f[i];else ++deg[i],++deg[f[i]],ff[i]=f[i];
		kk=0;
		F(i,0,n)if(deg[i]==1)last[find(i)]=~last[find(i)]?(a3[kk++]=i,a3[kk++]=last[find(i)],-1):i;
		else if(!deg[i])a3[kk++]=i,a3[kk++]=i;
		printf("%d\n",k);
		F(i,0,k)printf("%d %d %d %d\n",a1[i]+1,a2[i]+1,a3[i<<1|1]+1,a3[(i<<1)+2]+1);
	}
	return 0;
}