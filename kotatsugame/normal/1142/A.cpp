#include<iostream>
#include<algorithm>
using namespace std;
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
long long N,K,A,B;
main()
{
	cin>>N>>K>>A>>B;
	long long x=1e18,y=0;
	for(int d=-1;d<=1;d+=2)
	{
		long long s=1+A*d;
		if(s<0)s+=N*K;
		for(int j=0;j<N;j++)
		{
			for(int e=-1;e<=1;e+=2)
			{
				long long t=1+j*K+e*B;
				t%=N*K;
				if(t<0)t+=N*K;
				long long now=N*K/gcd(abs(s-t),N*K);
				if(x>now)x=now;
				if(y<now)y=now;
			}
		}
	}
	cout<<x<<" "<<y<<endl;
}