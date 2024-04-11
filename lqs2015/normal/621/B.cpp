#include<iostream>
#include<algorithm>
using namespace std;
long long a[222222],b[222222],c[222222],d[222222],ans,n,mx;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		c[i]=a[i]-b[i];
		d[i]=a[i]+b[i];
	}
	for (int i=-999;i<2000;i++)
	{
		int s1=0,s2=0;
		for (int j=1;j<=n;j++)
		{
			if (c[j]==i) s1++;
			if (d[j]==i) s2++;	
		}
		ans=ans+s1*(s1-1)/2+s2*(s2-1)/2;
	}
	cout<<ans<<endl;
	return 0;
}