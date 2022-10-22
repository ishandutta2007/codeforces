#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=20,MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,invfacn=1,ans;
long long s,a[N],sum[1<<N],A[1<<N];
int pow(int aa,int b)
{
	long long c=1,a=aa;
	while(b)
	{
		if(b&1)(c*=a)%=MOD;
		(a*=a)%=MOD;b>>=1;
	}
	return c;
}
int main()
{
	read(n);read(s);
	F(i,0,n)read(a[i]),A[1<<i]=a[i]+1;
	F(i,1,n)invfacn=invfacn*(long long)i%MOD;
	invfacn=pow(invfacn,MOD-2);
	F(i,0,1<<n)
	{
		int tmp=1;
		if(i)sum[i]=sum[i^(i&-i)]-A[i&-i];
		else sum[i]=s;
		if(sum[i]>=0)for(long long j=sum[i]+1,j_end=sum[i]+n;j<j_end;++j)tmp=j%MOD*tmp%MOD;
		else tmp=0;
		if(__builtin_popcount(i)&1)(ans+=MOD-tmp)%=MOD;
		else (ans+=tmp)%=MOD;
	}
	ans=ans*(long long)invfacn%MOD;
	printf("%d\n",ans);
	return 0;
}