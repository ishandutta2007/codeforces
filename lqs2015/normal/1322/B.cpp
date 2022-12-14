#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,test,a[444444],b[444444],ans,c[444444],l,r,p;
long long sum;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=0;i<=24;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (a[j]&(1<<i)) b[j]|=(1<<i);
		}
		for (int j=1;j<=n;j++) c[j]=b[j];
		sort(c+1,c+n+1);sum=0;
		for (int j=1;j<=n;j++)
		{
			l=lower_bound(c+1,c+n+1,(1<<i)-c[j])-c;
			r=lower_bound(c+1,c+n+1,(1<<(i+1))-c[j])-c;
			if (r>n || c[r]+c[j]>=(1<<(i+1))) r--;
			if (l<=r)
			{
				if (l<=j && r>=j) p=r-l;
				else p=r-l+1;
				sum+=p;
			}
			l=lower_bound(c+1,c+n+1,(1<<(i+1))+(1<<i)-c[j])-c;
			r=lower_bound(c+1,c+n+1,(1<<(i+2))-c[j])-c;
			if (r>n || c[r]+c[j]>=(1<<(i+2))) r--;
			if (l<=r)
			{
				if (l<=j && r>=j) p=r-l;
				else p=r-l+1;
				sum+=p;
			}
		}
		sum/=2;
		if (sum&1) ans^=(1<<i);
	}
	printf("%d\n",ans);
	return Accepted;
}