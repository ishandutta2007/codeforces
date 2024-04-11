#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
template<typename T>
T extgcd(T a,T b,T&x,T&y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	T q=a/b;
	T g=extgcd(b,a-q*b,y,x);
	y-=q*x;
	return g;
}
long long flr(long long A,long long B)
{
	return A>=0?A/B:A%B==0?A/B:A/B-1;
}
long long cil(long long A,long long B)
{
	return A>=0?(A+B-1)/B:A/B;
}
long long n,k,l,r,x;
long long ans=-1;
main()
{
	cin>>n>>l>>r>>k;
	l--,r--;
	r=(r-l+n)%n;
	x=r+1;
	if(k/n<1e7)
	{
		if(k>=x&&k-x<=x)
		{
			if(k-x<x)ans=n-x+k-x+1;
			else ans=n-x+k-x;
		}
		for(long long d=1;d<=k/n;d++)
		{
			long long K=k-n*d-x;
			if(K>=0)
			{
				long long a0=K,b0=-K;
				long long L,R;
				L=max(cil(a0-x,d),cil(-b0,d+1));
				R=min(flr(a0,d),flr(n-x-b0,d+1));
				if(L<=R)
				{
					long long ab=a0+b0+R;
					ans=max(ans,ab);
				}
			}
			if(K>=-1)
			{
				K++;
				long long a0=K,b0=-K;
				long long L,R;
				L=max(cil(a0-x,d),cil(-b0,d+1));
				R=min(flr(a0-1,d),flr(n-x-b0,d+1));
				if(L<=R)
				{
					long long ab=a0+b0+R;
					ans=max(ans,ab);
				}
			}
		}
	}
	else
	{
		if(k>=x&&(k-x)%n==0)ans=0;
		if(k==x)ans=1;
		for(long long a=0;a<=x;a++)for(long long b=0;b<=n-x;b++)
		{
			if(a+b==0)continue;
			if(k>=x+a&&(k-x-a)%(n+a+b)==0)ans=max(ans,a+b);
			if(a>0)
			{
				if(k>=x+a-1&&(k-x-a+1)%(n+a+b)==0)ans=max(ans,a+b);
			}
		}
	}
	printf("%lld\n",ans);
}