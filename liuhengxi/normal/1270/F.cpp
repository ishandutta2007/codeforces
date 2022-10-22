#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,M=1e8+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,b,bb,s[N],t[N],p[N],m,c[M];long long ans;
char a[N];
#define intersect min(lmax,rmax)-max(lmin,rmin)
inline long long divi(long long a,long long b)
{
	a-=((a%b)+b)%b;
	return a/b;
}
inline long long calc(long long lmin,long long lmax,long long rmin,long long rmax,long long step)
{
	long long ans=0,first,term;
	if(rmin>=lmax)for(long long delta=(rmin-lmax)/step*step+step;delta>0;delta=0)lmin+=delta,lmax+=delta;
	first=intersect;
	if(lmax<=rmax&&lmin<=rmin)
	{
		term=divi(min(rmax-lmax,rmin-lmin),step)+1;
		lmin+=(term-1)*step;lmax+=(term-1)*step;
		long long last=intersect;
		lmin+=step;lmax+=step;
		ans+=(last+first)*term>>1;
	}
	first=intersect;
	if(lmax<=rmax||lmin<=rmin)
	{
		term=divi(max(rmax-lmax,rmin-lmin),step)+1;
		lmin+=(term-1)*step;lmax+=(term-1)*step;
		lmin+=step;lmax+=step;
		ans+=first*term;
	}
	first=intersect;
	if(rmax-lmin>0)
	{
		term=divi(rmax-lmin+step-1,step);
		lmin+=(term-1)*step;lmax+=(term-1)*step;
		long long last=intersect;
		ans+=(last+first)*term>>1;
	}
	return ans;
}
int main()
{
	scanf("%s",a);
	while(a[n])++n;
	while(b*b<n)++b;
	F(i,0,n)s[i+1]=s[i]+(a[i]^48);
	F(k,1,b)
	{
		F(i,0,n+1)ans+=c[t[i]=s[i]*k-i+n]++;
		F(i,0,n+1)--c[t[i]];
	}
	bb=n/b;
	p[m++]=-1;
	F(i,0,n)if(a[i]=='1')p[m++]=i;
	p[m++]=n;
	F(k,1,bb+1)
	{
		F(i,1,m-k)
		{
			int j=i+k;
			int lmin=p[i-1]+1,lmax=p[i];
			int rmin=p[j-1]+1,rmax=p[j];
			ans+=calc(lmin,lmax+1,rmin-k*b,rmax-k*b+1,k);
		}
	}
	printf("%lld\n",ans);
	return 0;
}