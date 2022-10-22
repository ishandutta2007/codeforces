#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5;
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
}e[2*N];
struct o
{
	int a,k;
};
int n,a[N],hd[N],cnt;
long long s[N],sum,b[N],c[N],f[N],ans;
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
long long gcd(long long a,long long b){return !b?a:gcd(b,a%b);}
void dfs(int u,int fa)
{
	s[u]=a[u];
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dfs(v,u);
		s[u]+=s[v];
	}
}
int main()
{
	read(n);
	F(i,0,n)read(a[i]);
	F(i,0,n)hd[i]=-1;
	F(i,0,n-1)
	{
		int u,v=i+1;read(u);
		adline(--u,v);adline(v,u);
	}
	dfs(0,0);
	sum=s[0];
	F(i,0,n)
	{
		long long k=sum/gcd(sum,s[i]);
		if(k<=n)++b[k];
	}
	F(i,1,n+1)for(int j=i;j<=n;j+=i)c[j]+=b[i];
	F(i,1,n+1)if(c[i]>=i)f[i]=1;
	F(i,2,n+1)for(int j=2*i;j<=n;j+=i)if(f[j])f[j]+=f[i];
	F(i,1,n+1)ans+=f[i];
	printf("%lld\n",ans);
	return 0;
}