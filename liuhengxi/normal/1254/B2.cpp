#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5;
const long long LLINF=0x3fffffffffffffffll;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N];
long long sum,ans=LLINF;
void solve(long long k)
{
	long long t0,t1,a0,a1;
	long long t0_,t1_,a0_,a1_;
	a0=t0=a[0]%k;
	a1=(k-a[0]%k)%k;
	t1=-(k-a[0]%k)%k;
	F(i,1,n)
	{
		t0_=(a[i]+t0)%k;
		t1_=-(k-t0_)%k;
		a0_=a0+(a[i]+t0)%k;
		if(a[i]+t1>=0)a0_=min(a0_,a1+(a[i]+t1)%k);
		a1_=min(a0+(k-(a[i]+t0)%k)%k,a1+(k-(a[i]+t1)%k)%k);
		t0=t0_;
		t1=t1_;
		a0=a0_;
		a1=a1_;
	}
	ans=min(ans,a0);
	ans=min(ans,a1);
}
int main()
{
	read(n);
	F(i,0,n)read(a[i]),sum+=a[i];
	if(sum==1)return puts("-1"),0;
	for(int i=2;(long long)i*i<=sum;++i)if(sum%i==0)
	{
		solve(i);
		while(sum%i==0)sum/=i;
	}
	if(sum!=1)solve(sum);
	printf("%lld\n",ans);
	return 0;
}