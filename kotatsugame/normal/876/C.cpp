#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
vector<long long>s;
main()
{
	long long n;cin>>n;
	for(long long i=0;i<=100&&i<=n;i++)
	{
		long long N=n-i;
		long long sum=N;
		while(N>0)
		{
			sum+=N%10;
			N/=10;
		}
		if(sum==n)
		{
			s.push_back(n-i);
		}
	}
	cout<<s.size()<<endl;
	for(int i=s.size();i--;)
	{
		printf("%lld\n",s[i]);
	}
}