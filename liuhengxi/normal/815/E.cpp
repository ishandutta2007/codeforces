#include<cstdio>
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
int log2(long long x){return 63-__builtin_clzll(x);}
long long dfsa(long long n,long long m,long long k)
{
	if(n==1)return 0;
	long long l=(m+1)>>1;
	if(k<l)return dfsa(n>>1,l,k);
	return dfsa(n>>1,m>>1,k-l)+(n>>1);
}
long long dfsb(long long l,long long r,long long dep,long long k)
{
	long long mid=(l+r)>>1;
	if(dep==0)return mid;
	long long half=1ll<<(dep-1);
	if(k<half)return dfsb(l,mid,dep-1,k);
	return dfsb(mid,r,dep-1,k-half);
}
long long dfsc(long long l,long long r,long long dep,long long k)
{
	if(dep==0)return l+1+k;
	long long mid=(l+r)>>1;
	long long left=mid-l-(1ll<<(dep-1));
	if(k<left)return dfsc(l,mid,dep-1,k);
	return dfsc(mid,r,dep-1,k-left);
}
long long dfsd(long long l,long long r,long long dep,long long k)
{
	if(dep==0)return l+2+k;
	long long mid=(l+r)>>1;
	long long left=mid-l-(3ll<<(dep-1));
	if(k<left)return dfsd(l,mid,dep-1,k);
	return dfsd(mid,r,dep-1,k-left);
}
long long dfse(long long l,long long r,long long dep,long long k)
{
	if(dep==0)return l+1+k*((r-l)>>1);
	long long mid=(l+r)>>1;
	long long left=1ll<<dep;
	if(k<left)return dfse(l,mid,dep-1,k);
	return dfse(mid,r,dep-1,k-left);
}
long long n,k,lim;
int main()
{
	read(n,k);
	if(k<=2)return printf("%lld\n",k==2?n:1),0;
	k-=2;
	lim=(1ll<<(log2(n-1)-1))-1;
	if(k<=lim)
	{
		int dep=log2(k);
		long long s=k^(1ll<<dep);
		if(((n-1)>>dep)&1)
		{
			long long r=(n-1)&((1ll<<dep)-1);
			if(s<r)printf("%lld\n",dfsb(1,n,dep,(1ll<<dep)-1-dfsa(1ll<<dep,r,r-1-s)));
			else printf("%lld\n",dfsb(1,n,dep,dfsa(1ll<<dep,(1ll<<dep)-r,s-r)));
		}
		else printf("%lld\n",dfsb(1,n,dep,s));
	}
	else
	{
		int dep=log2(n-1)-1;
		k-=lim+1;
		if(n-1<(3ll<<dep))printf("%lld\n",dfsc(1,n,dep,k));
		else
		{
			if(k<n-1-(3ll<<dep))printf("%lld\n",dfsd(1,n,dep,k));
			else
			{
				k-=n-1-(3ll<<dep);
				printf("%lld\n",dfse(1,n,dep,k));
			}
		}
	}
	return 0;
}