#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5;
const long long LLINF=0x3fffffffffffffffll;
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
struct BITb
{
	static const int N=::N<<1;
	int n;long long c[N];
	void init(int n_){n=n_;}
	void add(int x,long long y){for(++x;x<=n;x+=x&-x)c[x]+=y;}
	long long sum(int x){long long ans=0;for(;x;x-=x&-x)ans+=c[x];return ans;}
	int binary(int x)
	{
		int ans=0;
		for(int delta=1<<(31-__builtin_clz(n));delta;delta>>=1)
			if(ans+delta<=n&&c[ans+delta]<=x)x-=c[ans+=delta];
		return ans;
	}
}c,d;
struct box{int a,b,id;}a[N];
bool operator<(box u,box v){return u.b<v.b;}
int n,w,id[2*N],f[N],s[N],p;
long long ans=LLINF,cur;
char r[N];
bool cmp(int u,int v){return (u&1?s:f)[u>>1]<(v&1?s:f)[v>>1];}
bool cmp2(int u,int v){return f[u]<f[v];}
int main()
{
	read(n,w);
	F(i,0,n)read(a[a[i].id=i].a,a[i].b);
	sort(a,a+n);
	F(i,0,n)f[i]=a[i].a,s[i]=a[i].b-a[i].a;
	F(i,0,2*n)id[i]=i;
	sort(id,id+2*n,cmp);
	F(i,0,2*n)(id[i]&1?s:f)[id[i]>>1]=i;
	c.init(2*n);d.init(2*n);
	F(i,0,n)c.add(f[i],1),d.add(f[i],a[i].a);
	for(int i=0;;++i)
	{
		int need=w-i;
		if(need>=0&&need<=n)
		{
			long long tmp=d.sum(c.binary(need))+cur;
			if(tmp<ans)ans=tmp,p=i;
		}
		if(i==n)break;
		c.add(f[i],-1),d.add(f[i],-a[i].a);
		c.add(s[i],1),d.add(s[i],a[i].b-a[i].a);
		cur+=a[i].a;
	}
	F(i,0,p)f[i]=a[i].b-a[i].a,r[a[i].id]='1';
	F(i,p,n)f[i]=a[i].a,r[a[i].id]='0';
	F(i,0,n)id[i]=i;
	sort(id,id+n,cmp2);
	int need=w-p;
	F(i,0,need)++r[a[id[i]].id];
	printf("%lld\n",ans);
	puts(r);
	return 0;
}