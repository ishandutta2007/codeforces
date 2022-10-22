#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5,MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,k,a[N],id[N],last,now,ans,g[N],f[N],s[N];bool b[N];
bool cmp(int u,int v){return a[u]<a[v];}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void merge(int u,int v)
{
	(now+=(g[s[u]]+g[s[v]])%MOD)%=MOD;
	s[f[v]=u]+=s[v];
	(now+=MOD-g[s[u]])%=MOD;
}
void add(int u)
{
	s[u]=1;b[u]=true;
	if(u&&b[u-1])merge(find(u-1),find(u));
	if(u<n-1&&b[u+1])merge(find(u+1),find(u));
}
int main()
{
	read(n);read(k);--k;
	F(i,0,n)read(a[i]),id[i]=i;
	sort(id,id+n,cmp);
	F(i,0,n+1)g[i]=i;
	F(i,k,n+1)(g[i]+=g[i-k])%=MOD;
	F(i,0,n+1)(g[i]+=MOD-i)%=MOD;
	now=g[n];
	F(i,0,n)f[i]=i;
	F(i,0,n)
	{
		(ans+=(long long)(a[id[i]]-last)*now%MOD)%=MOD;
		last=a[id[i]];
		add(id[i]);
	}
	printf("%d\n",ans);
	return 0;
}