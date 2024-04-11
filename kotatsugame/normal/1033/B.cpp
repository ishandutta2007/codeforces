#include<iostream>
using namespace std;
long long a,b;
main()
{
	int t;cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>a>>b;
		if(a-b!=1)cout<<"NO"<<endl;
		else
		{
			a=2*b+1;
			bool f=1;
			for(long long j=2;j*j<=a;j++)if(a%j<1)
			{
				f=0;
				break;
			}
			cout<<(f?"YES":"NO")<<endl;
		}
	}
}