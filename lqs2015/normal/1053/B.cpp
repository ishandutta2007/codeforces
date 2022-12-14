#include<iostream>
#include<cstdio>
#include<deque>
using namespace std;
long long n,a[333333],ev,od,x,ans,sz,l[333333],r[333333],L,R,mid,sum,bit[2222222],mx;
deque<pair<long long,long long> > q;
void update(long long p)
{
	while(p<=sz)
	{
		bit[p]++;
		p+=p&(-p);
	}
}
long long summ(long long p)
{
	if (p<=0) return 0;
	long long res=0;
	while(p>=1)
	{
		res+=bit[p];
		p-=p&(-p);
	}
	return res;
}
int main()
{
	scanf("%I64d",&n);
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d",&x);
		while(x)
		{
			if (x&1ll) a[i]++;
			x>>=1ll;
		}
	}
	ev++;
	for (int i=1;i<=n;i++)
	{
		sum+=a[i];
		if (sum&1ll) ans+=od,od++;
		else ans+=ev,ev++;
	}
	for (int i=1;i<=n;i++)
	{
		sum=mx=0;
		for (int j=i;j<=n && j<=i+64;j++)
		{
			sum+=a[j];
			mx=max(mx,a[j]);
			if (sum%2==0 && mx*2>sum) ans--;  
		}
	}
	printf("%I64d\n",ans);
	return 0;
}