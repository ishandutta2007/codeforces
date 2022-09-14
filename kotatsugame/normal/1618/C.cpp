#include<iostream>
using namespace std;
int T,N;
long long A[100];
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		long long ans=0;
		for(int t=0;t<2;t++)
		{
			long long g=0;
			for(int i=t;i<N;i+=2)g=gcd(g,A[i]);
			bool ok=true;
			for(int i=1-t;i<N;i+=2)if(A[i]%g==0)ok=false;
			if(ok)ans=g;
		}
		cout<<ans<<"\n";
	}
}