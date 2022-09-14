#include<iostream>
#include<algorithm>
using namespace std;
int N;
main()
{
	cin>>N;
	int dp0=0,dp1=-1e9;
	for(int i=0;i<N;i++)
	{
		int a;cin>>a;
		int ndp0,ndp1;
		if(a%2==0)
		{
			ndp0=dp0+a;
			ndp1=dp1+a;
		}
		else
		{
			ndp0=dp1+a;
			ndp1=dp0+a;
		}
		dp0=max(dp0,ndp0);
		dp1=max(dp1,ndp1);
	}
	cout<<dp1<<endl;
}