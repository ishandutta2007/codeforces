#include<cstdio>
#include<cstring>
#include<random>
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
mt19937 rnd(79774871);
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
void factor(int x,int *p,int &t)
{
	t=0;
	for(int i=2;i*i<=x;++i)if(x%i==0)
	{
		p[t++]=i;
		do x/=i;while(x%i==0);
	}
	if(x>1)p[t++]=x;
}
int n,aa[N],id[N],a[N],p0[N],t0,p1[N],t1,c0[N],c1[N],f[(1<<18)+5],pre[(1<<18)+5],ans[N];
bool solve()
{
	factor(a[1],p1,t1);
	memset(f,-1,sizeof(int)<<(t0+t1));
	f[0]=0;
	F(i,0,t0)c0[i]=0;
	F(i,0,t1)c1[i]=0;
	F(i,2,n)
	{
		bool ok=false;
		F(j,0,t0)if(a[i]%p0[j])if(++c0[j]<=20)ok=true;
		F(j,0,t1)if(a[i]%p1[j])if(++c1[j]<=20)ok=true;
		if(ok)
		{
			int b0=0,b1=0;
			F(j,0,t0)if(a[i]%p0[j])b0^=1<<j;
			F(j,0,t1)if(a[i]%p1[j])b1^=1<<j;
			b1<<=t0;
			F(j,0,1<<(t0+t1))if(~f[j]&&(f[j]>>1)<i)
			{
				if(!~f[j|b0])f[j|b0]=i<<1,pre[j|b0]=j;
				if(!~f[j|b1])f[j|b1]=i<<1|1,pre[j|b1]=j;
			}
		}
	}
	int x=(1<<(t0+t1))-1;
	if(!~f[x])return false;
	ans[id[1]]=1;
	while(x)
	{
		if(f[x]&1)ans[id[f[x]>>1]]=1;
		x=pre[x];
	}
	puts("YES");
	F(i,0,n)printf("%d ",ans[i]+1);
	puts("");
	return true;
}
int main()
{
	F(i,0,read(n))read(a[i]);
	if(n<=20)
	{
		static int g[(1<<20)+5];
		F(i,1,1<<n)
		{
			int j=__builtin_ctz(i);
			g[i]=gcd(g[i^1<<j],a[j]);
		}
		int full=(1<<n)-1;
		F(i,1,1<<(n-1))if(g[i]==1&&g[i^full]==1)
		{
			puts("YES");
			F(j,0,n)printf("%d ",(i>>j&1)+1);
			puts("");
			return 0;
		}
		return puts("NO"),0;
	}
	F(i,0,n)id[i]=i;
	shuffle(id,id+n,rnd);
	F(i,0,n)aa[i]=a[i];
	F(i,0,n)a[i]=aa[id[i]];
	factor(a[0],p0,t0);
	F(i,1,11)
	{
		if(i>1)swap(a[i],a[1]),swap(id[i],id[1]);
		if(solve())return 0;
		if(i>1)swap(a[i],a[1]),swap(id[i],id[1]);
	}
	puts("NO");
	return 0;
}