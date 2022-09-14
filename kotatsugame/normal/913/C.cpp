#include<iostream>
using namespace std;
long long l,c[33];int n;
main()
{
	cin>>n>>l;
	for(int i=0;i<n;i++)cin>>c[i];
	for(int i=1;i<32;i++)
	{
		if(c[i]>c[i-1]*2||c[i]==0)c[i]=c[i-1]*2;
	}
	long long ans;
	for(int i=0;i<32;i++)
	{
		if(i==0)ans=l%2*c[0];
		else
		{
			if(ans>c[i])ans=c[i];
			ans+=(l&(1LL<<i))?c[i]:0;
		}
	}
	cout<<ans<<endl;
}