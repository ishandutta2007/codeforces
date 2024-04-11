#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[222222],b[222222],c[222222],n,sum,k;
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		sum+=b[i];
		c[i]=a[i]-b[i];
	}
	sort(c+1,c+n+1);
	for (int i=1;i<=k;i++)
	{
		sum+=c[i];
	}
	k++;
	while(k<=n && c[k]<0)
	{
		sum+=c[k];
		k++;
	}
	cout<<sum<<endl;
	return 0;
}