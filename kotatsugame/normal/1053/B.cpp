#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
long long ans;int n,a[3<<17];
int cumsum[3<<17];
main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		long long x;scanf("%lld",&x);
		a[i]=__builtin_popcountll(x);
	}
	int cnt[2]={1,0};
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum=(sum+a[i])%2;
		ans+=cnt[sum]++;
		cumsum[i+1]=cumsum[i]+a[i];
	}
	for(int i=0;i<n;i++)
	{
		int l=i,r=i,lsum=a[i],rsum=a[i];
		while(l>0&&(lsum+a[l-1])<a[i]*2)lsum+=a[--l];
		while(r<n-1&&(rsum+a[r+1])<a[i]*2)rsum+=a[++r];
		for(int j=l;j<=i;j++)
		{
			for(int k=i;k<=r;k++)
			{
				int t=cumsum[k+1]-cumsum[j];
				ans-=t%2==0&&t<a[i]*2;
			}
		}
	}
	cout<<ans<<endl;
}