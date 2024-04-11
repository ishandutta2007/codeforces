#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,MOD=998244353;
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
	int next,to;
}e[N];
int n,p[N],hd[N],cnt,f[N][3];
bool leaf[N];
inline void adline(int u,int v){e[cnt].to=v;e[cnt].next=hd[u];hd[u]=cnt++;}
void dfs(int u)
{
	if(!~hd[u])return f[u][0]=1,f[u][1]=1,f[u][2]=0,void();
	f[u][0]=1;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;auto &g=f[v];
		dfs(v);
		f[u][2]=(f[u][2]*((long long)g[0]+g[1]+g[2])+f[u][1]*(long long)(g[1]+g[2]))%MOD;
		f[u][1]=(f[u][1]*(long long)g[0]+f[u][0]*(long long)(g[1]+g[2]))%MOD;
		f[u][0]=f[u][0]*(long long)g[0]%MOD;
	}
	(f[u][0]+=f[u][2])%=MOD;
}
int main()
{
	F(i,0,read(n))hd[i]=-1;
	F(i,1,n)adline(--read(p[i]),i);
	dfs(0);
	printf("%d\n",f[0][0]);
	return 0;
}