#include<iostream>
using namespace std;
main()
{
	long long l,r,x,y,k;
	cin>>l>>r>>x>>y>>k;
	bool flag=false;
	for(long long i=x;i<=y;i++)
	{
		long long p=k*i;
		flag|=l<=p&&p<=r;
	}
	cout<<(flag?"YES":"NO")<<endl;
}