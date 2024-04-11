#include<iostream>
using namespace std;
int q;
main()
{
	cin>>q;
	for(;q--;)
	{
		long long a;cin>>a;
		long long t=1;
		while(t<=a)t*=2;
		if(t-1==a)
		{
			long long ans=1;
			for(long long i=2;i*i<=a;i++)
			{
				if(a%i==0)
				{
					ans=a/i;
					break;
				}
			}
			cout<<ans<<endl;
		}
		else
		{
			cout<<t-1<<endl;
		}
	}
}