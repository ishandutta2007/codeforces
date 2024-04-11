#include<iostream>
using namespace std;
long long X,Y;
long long gcd(long long A,long long B){return B?gcd(B,A%B):A;}
main()
{
	cin>>X>>Y;
	long long ans=0;
	while(Y)
	{
		long long T=X;
		long long r=Y;
		for(long long p=2;p*p<=T;p++)if(T%p==0)
		{
			while(T%p==0)T/=p;
			long long now=Y%p;
			if(r>now)r=now;
		}
		if(T>1)
		{
			long long now=Y%T;
			if(r>now)r=now;
		}
		ans+=r;
		Y-=r;
		if(Y)
		{
			long long g=gcd(X,Y);
			X/=g,Y/=g;Y--;
			ans++;
		}
	}
	cout<<ans<<endl;
}