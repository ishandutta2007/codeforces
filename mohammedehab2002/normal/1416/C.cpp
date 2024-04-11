#include <bits/stdc++.h>
using namespace std;
int b,a[300005];
bool cmp(int x,int y)
{
	x&=((1<<30)-(1<<(b+1)));
	y&=((1<<30)-(1<<(b+1)));
	return (x<y);
}
int main()
{
	int n;
	scanf("%d",&n);
	vector<int> v;
	for (int i=0;i<n;i++)
	scanf("%d",&a[i]);
	int x=0;
	long long ans=0;
	for (b=29;b>=0;b--)
	{
		stable_sort(a,a+n,cmp);
		int o=0,z=0;
		long long inv0=0,inv1=0;
		for (int i=0;i<n;i++)
		{
			if (i && cmp(a[i-1],a[i]))
			{
				o=0;
				z=0;
			}
			if (a[i]&(1<<b))
			{
				o++;
				inv1+=z;
			}
			else
			{
				z++;
				inv0+=o;
			}
		}
		if (inv0>inv1)
		{
			x^=(1<<b);
			for (int i=0;i<n;i++)
			a[i]^=(1<<b);
			swap(inv0,inv1);
		}
		ans+=inv0;
	}
	printf("%lld %d",ans,x);
}