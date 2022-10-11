#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005];
long long b[500005];
long long get(int sz)
{
	int need=sz-1;
	long long tmp=b[0]*need;
	for (int i=1;i<n;i++)
	{
		if (need-1>=(n-i-1-need)/k)
		{
			need--;
			tmp+=b[i]*need;
		}
		else
		tmp+=b[i]*((n-i-1-need)/k);
	}
	return tmp;
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++)
	scanf("%d",&a[i]);
	sort(a,a+n,greater<int>());
	int p=0;
	long long ans=0,cur=0;
	for (;p<n && a[p]>=0;p++)
	{
		ans+=cur;
		cur+=a[p];
	}
	for (int i=p;i<n;i++)
	b[i-p+1]=a[i];
	b[0]=cur;
	n=n-p+1;
	if (!k)
	{
		for (int i=1;i<n;i++)
		{
			ans+=cur;
			cur+=b[i];
		}
		printf("%I64d",ans);
	}
	else
	{
		int st=1,en=n;
		while (st!=en)
		{
			int l=(en-st)/3;
			if (get(st+l)<get(en-l))
			st=st+l+1;
			else
			en=en-l-1;
		}
		printf("%I64d",ans+get(st));
	}
}