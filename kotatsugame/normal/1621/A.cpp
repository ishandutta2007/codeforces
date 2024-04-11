#include<iostream>
using namespace std;
int T,N,K;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>K;
		if(K*2-1>N)
		{
			cout<<"-1\n";
		}
		else
		{
			for(int i=0;i<N;i++)
			{
				if(i%2==0&&K>0)
				{
					K--;
					for(int j=0;j<N;j++)cout<<(i==j?'R':'.');
					cout<<"\n";
				}
				else
				{
					for(int j=0;j<N;j++)cout<<'.';
					cout<<"\n";
				}
			}
		}
	}
}