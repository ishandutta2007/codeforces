#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,LogN=19;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,log1n,a[N],t,l[N],r[N],s[2*N][LogN],g[N],log1[N],b[N],id[N],ans[N],c[N];
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
bool cmp1(int x,int y){return a[x]!=a[y]?a[x]<a[y]:x<y;}
bool cmp2(int a,int b){return g[a]<g[b];}
void add(int x,int y){for(++x;x<=n;x+=x&-x)c[x]+=y;}
int sum(int x){int ans=0;for(;x;x-=x&-x)ans+=c[x];return ans;}
int main()
{
	read(n);F(i,0,n)read(a[i]),b[i]=i;
	read(t);F(i,0,t)read(l[i]),read(r[i]),--l[i];
	F(i,0,n)s[i][0]=a[i];
	while((1<<log1n)<n)++log1n;
	F(i,0,log1n-1)F(j,0,n)s[j][i+1]=gcd(s[j][i],s[j+(1<<i)][i]);
	F(i,1,n+2)log1[i]=log1[i-1]+((1<<log1[i-1])<i?1:0);
	F(i,0,t)
	{
		int x=log1[r[i]-l[i]+1]-1;
		g[i]=gcd(s[l[i]][x],s[r[i]-(1<<x)][x]);
		id[i]=i;ans[i]=r[i]-l[i];
	}
	sort(b,b+n,cmp1);sort(id,id+t,cmp2);
	for(int ll=0,rr=0,i=0;ll<n;ll=rr)
	{
		while(rr<n&&a[b[rr]]==a[b[ll]])++rr;
		F(j,ll,rr)add(b[j],1);
		while(i<t&&g[id[i]]<a[b[ll]])++i;
		for(int j=id[i];i<t&&g[id[i]]==a[b[ll]];j=id[++i])
			ans[j]=r[j]-l[j]-sum(r[j])+sum(l[j]);
		F(j,ll,rr)add(b[j],-1);
	}
	F(i,0,t)printf("%d\n",ans[i]);
	return 0;
}