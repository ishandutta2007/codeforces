#include<iostream>
using namespace std;
long long N;
main()
{
	int cnt=0;
	for(int i=1;i<=2520;i++)
	{
		bool now=true;
		for(int j=2;j<=10;j++)if(i%j==0)now=false;
		if(now)cnt++;
	}
	long long N;
	cin>>N;
	long long ans=N/2520*cnt;
	N%=2520;
	for(int i=1;i<=N;i++)
	{
		bool now=true;
		for(int j=2;j<=10;j++)if(i%j==0)now=false;
		if(now)ans++;
	}
	cout<<ans<<endl;
}