#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,k,t;
	cin>>n>>k>>t;
	long long ans;
	if(t<=k)
	{
		ans=t;
	}
	if(t>k&&t<n)
	{
		ans=k;
	}
	if(t>=n)
	{
		ans=(n+k-t);
	}
	cout<<ans<<endl;
}