#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
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
int n,p[N],s[N],hd[N],cnt;
long long a[N],fr[N],f[N];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u)
{
	long long max=0;
	if(hd[u]==-1)s[u]=1;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		dfs(v);
		a[u]-=fr[v];
		if(max<f[v])
		{
			a[u]-=s[u]*(f[v]-max);
			max=f[v];
		}
		s[u]+=s[v];
		a[u]-=(max-f[v])*s[v];
	}
	if(a[u]<0)fr[u]=-a[u],a[u]=0;
	f[u]=max+(a[u]+s[u]-1)/s[u];
	fr[u]+=(a[u]+s[u]-1)/s[u]*s[u]-a[u];
}
int main()
{
	read(n);
	F(i,0,n)hd[i]=-1;
	F(i,1,n)
	{
		read(p[i]);
		adline(--p[i],i);
	}
	F(i,0,n)read(a[i]);
	dfs(0);
	printf("%lld\n",f[0]);
	return 0;
}