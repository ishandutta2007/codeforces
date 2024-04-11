#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,s,a[222222],b[222222],c[222222],cb,cc,cd,ans;
int main()
{
	scanf("%I64d%I64d",&n,&s);
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		if (a[i]<s) b[++cb]=a[i];
		else if (a[i]>s) c[++cc]=a[i];
		else ++cd;
	}
	if (cb>=(n+1)/2)
	{
		sort(b+1,b+cb+1);
		for (long long i=cb;i>=(n+1)/2;i--)
		{
			ans+=(s-b[i]);
		}
	}
	else if (cc>=(n+1)/2)
	{
		sort(c+1,c+cc+1);
		for (long long i=1;i<=cc-(n+1)/2+1;i++)
		{
			ans+=(c[i]-s);
		}
	}
	cout<<ans<<endl;
	return 0;
}