#include<cstdio>
#include<algorithm>
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
constexpr int N=1e5+5;
int pool[N<<5],*cur=pool;
int fc[N],*factor[N],mu[N];
void init(int n)
{
	F(i,1,n+1)for(int j=i;j<=n;j+=i)++fc[j];
	F(i,0,n+1)factor[i]=cur,cur+=fc[i],fc[i]=0;
	F(i,1,n+1)for(int j=i;j<=n;j+=i)factor[j][fc[j]++]=i;
	mu[1]=1;
	F(i,2,n+1)
	{
		int p=factor[i][1],q=i/p;
		if(q%p)mu[i]=-mu[q];
	}
}
int gcd(int a,int b)
{
	int c,d,e=0;
	a>>=c=__builtin_ctz(a);
	b>>=d=__builtin_ctz(b);
	e+=min(c,d);
	while(a&&b&&(a^b))
	{
		if(a>b)a>>=c=__builtin_ctz(a-=b);
		else b>>=d=__builtin_ctz(b-=a);
	}
	return (a|b)<<e;
}
int m,a[N],mx,s[N],t,c[N];bool b[N];long long ans;
void add(int x){F(i,0,fc[x])++c[factor[x][i]];}
void del(int x){F(i,0,fc[x])--c[factor[x][i]];}
int sum(int x){int ss=0;F(i,0,fc[x])ss+=mu[factor[x][i]]*c[factor[x][i]];return ss;}
void solve(int d)
{
	long long l=0;
	m=0;
	for(int i=mx/d;i;--i)if(b[i*d])a[m++]=i;
	F(i,0,m)
	{
		while(sum(a[i]))
		{
			del(s[--t]);
			l=max(l,(a[i]/gcd(a[i],s[t]))*(long long)s[t]);
		}
		add(s[t++]=a[i]);
	}
	while(t)del(s[--t]);
	ans=max(ans,l*d);
}
int main()
{
	F(i,0,read(m))
	{
		int x;
		b[read(x)]=true;
		mx=max(mx,x);
	}
	init(mx);
	ans=mx;
	F(i,1,mx+1)solve(i);
	printf("%lld\n",ans);
	return 0;
}