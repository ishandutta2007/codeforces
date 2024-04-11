#include<iostream>
using namespace std;
long long N,K;
main()
{
	cin>>N>>K;
	long long mg=2*N/K/(K+1);
	long long g=0;
	for(long long i=1;i*i<=N;i++)if(N%i==0)
	{
		long long ng=i;
		if(ng<=mg&&g<ng)g=ng;
		ng=N/i;
		if(ng<=mg&&g<ng)g=ng;
	}
	if(g==0)
	{
		cout<<-1<<endl;
		return 0;
	}
	long long c=N/g;
	for(int i=1;i<K;i++)
	{
		c-=i;
		cout<<i*g<<" ";
	}
	cout<<c*g<<endl;
}