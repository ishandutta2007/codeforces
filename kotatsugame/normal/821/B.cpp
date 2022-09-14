#include<iostream>
using namespace std;
main()
{
	long long ans=0,m,b,i;cin>>m>>b;
	for(i=0;i<=b;i++)
	{
		long long now=0;
		now=(i*m+1)*(b-i+1)*(i*m+b-i)/2;
		if(ans<now)ans=now;
	}
	cout<<ans<<endl;
}