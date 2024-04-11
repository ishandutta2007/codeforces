#include<cstdio>
#include<random>
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
constexpr int N=1e6+5,W=20;
mt19937 rnd(79774871);
long long gcd(long long a,long long b){return !b?a:gcd(b,a%b);}
int r[W],t;
long long p[W];
void factor(long long x)
{
	t=0;
	for(long long i=2;i*i<=x;++i)if(x%i==0)
	{
		p[t]=i;
		r[t]=0;
		while(x%i==0)x/=i,++r[t];
		++t;
	}
	if(x>1)p[t]=x,r[t]=1,++t;
}
int n,c[N],d,w[W],lim;
long long a[N],f[N],v[N],ans;
int main()
{
	read(n);
	F(i,0,n)read(a[i]);
	if(n==1)return printf("%lld\n",a[0]),0;
	lim=(n+1)>>1;
	F(_,0,8)
	{
		swap(a[0],a[rnd()%(n-1)+1]);
		factor(a[0]);
		d=1;
		v[0]=1;
		F(i,0,t)
		{
			w[i]=d;
			F(j,d,d*r[i]+d)v[j]=v[j-d]*p[i];
			d*=r[i]+1;
		}
		F(i,0,d)c[i]=0;
		F(i,0,n)
		{
			int m=0;
			long long x=gcd(a[i],a[0]);
			F(j,0,t)while(x%p[j]==0)m+=w[j],x/=p[j];
			++c[m];
		}
		F(i,0,t)
		{
			int s=w[i]*(r[i]+1);
			for(int b=0;b<d;b+=s)for(int j=b+s,je=b+w[i];--j>=je;)c[j-w[i]]+=c[j];
		}
		F(i,0,d)if(c[i]>=lim)ans=max(ans,v[i]);
	}
	printf("%lld\n",ans);
	return 0;
}