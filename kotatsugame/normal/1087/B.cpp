#include<iostream>
using namespace std;
int N,K;
main()
{
	cin>>N>>K;
	int ans=2e9;
	for(int i=1;i<K;i++)if(N%i==0)
	{
		int now=N/i*K+i;
		if(ans>now)ans=now;
	}
	cout<<ans<<endl;
}