#include<iostream>
using namespace std;
long long pw(long long a,long long b){return b?pw(a*a,b/2)*(b%2?a:1):1;}
main()
{
	long long N;
	cin>>N;
	long long ans=0;
	for(int L=0;L<=N-2;L++)
	{
		int R=N-2-L;
		long long now=4;
		if(R>0)now*=3*pw(4,R-1);
		if(L>0)now*=3*pw(4,L-1);
		ans+=now;
	}
	cout<<ans<<endl;
}