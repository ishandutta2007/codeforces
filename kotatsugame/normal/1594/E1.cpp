#include<iostream>
using namespace std;
const long long m1=1e9+7,m2=1e9+6;
main()
{
	int K;cin>>K;
	int p=((1LL<<K)-2)%m2;
	long long a=6,b=4;
	while(p)
	{
		if(p&1)a=a*b%m1;
		if(p>>=1)b=b*b%m1;
	}
	cout<<a%m1<<endl;
}