#include<iostream>
#include<cstdio>
using namespace std;
long long n,h;
long long get_ans(long long s,long long e,long long x){return (s+e)*x/2;}
long long check(long long x)
{
	long long sum=get_ans(1,x,x),used=x;
	if(x>h)sum+=get_ans(h,x-1,x-h),used+=x-h;
	long long s=n-sum;
	if(s<0)return -1;
	if(s>3*x)return -2;
	else if(s>2*x)return used+3;
	else if(s>x)return used+2;
	else if(s>0)return used+1;
	else return used;
}
int main()
{
	scanf("%lld%lld",&n,&h);
	long long l=1,r=2e9,ans=1e18;
	while(l<r)
	{
		long long mid=l+r>>1;
		long long k=check(mid);
		if(k==-1)r=mid;
		else
		{
			l=mid+1;
			if(k!=-2)ans=min(ans,k);
		}
	}
	printf("%lld",ans);return 0;
}