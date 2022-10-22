#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3005,MOD=1000000007;
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
}e[N];
int n,d,hd[N],cnt,f[N][N],ans;
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u)
{
	F(i,0,n+1)f[u][i]=1;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		dfs(v);
		F(i,0,n+1)f[u][i]=(long long)f[u][i]*f[v][i]%MOD;
	}
	F(i,1,n+1)f[u][i]=(f[u][i]+f[u][i-1])%MOD;
}
int inv(int aa)
{
	int b=MOD-2;
	long long a=aa,c=1;
	while(b)
	{
		if(b&1)c=c*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return (int)c;
}
int main()
{
	read(n);read(d);--d;
	F(i,0,n)hd[i]=-1;
	F(i,1,n)
	{
		int p;read(p);
		adline(--p,i);
	}
	dfs(0);
	F(i,0,n+1)
	{
		int tmp=f[0][i];
		long long div=1;
		F(j,0,n+1)if(j!=i)div=div*(i-j)%MOD;
		tmp=(long long)tmp*inv((int)div)%MOD;
		F(j,0,n+1)if(j!=i)tmp=(long long)tmp*(d-j)%MOD;
		ans=(ans+tmp)%MOD;
	}
	ans+=MOD;ans%=MOD;
	printf("%d\n",ans);
	return 0;
}