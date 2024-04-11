#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
const long long BMAX=10000000000000000;
template<typename T>T& read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
	return x;
}
int n,k,b[N],c[N];
bool need[N];
long long a[N];
bool check(long long x)
{
	int cnt=0;
	F(i,0,k+1)c[i]=0;
	F(i,0,n)
	{
		long long now=a[i]/b[i],energy=a[i]-now*b[i];++now;
		while(now<k)
		{
			++c[now];energy+=x;
			if(k<++cnt)return false;
			now+=energy/b[i];energy%=b[i];
		}
	}
	F(i,0,k)c[i+1]+=c[i];
	F(i,0,k+1)if(c[i]>i)return false;
	return true;
}
long long solve()
{
	long long l=-1,r=BMAX,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid;
	}
	return r;
}
int main()
{
	read(n);read(k);
	F(i,0,n)read(a[i]);
	F(i,0,n)read(b[i]);
	printf("%lld\n",check(BMAX)?solve():-1);
	return 0;
}