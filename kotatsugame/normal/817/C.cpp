#include<iostream>
using namespace std;
long long N,S;
int f(long long T)
{
	int ret=0;
	while(T)ret+=T%10,T/=10;
	return ret;
}
main()
{
	cin>>N>>S;
	long long L=0,R=3e18;
	while(R-L>1)
	{
		long long mid=(L+R)/2;
		if(mid-f(mid)>=S)R=mid;
		else L=mid;
	}
	long long ans=N-R+1;
	if(ans<0)ans=0;
	cout<<ans<<endl;
}