#include<iostream>
using namespace std;
int T;
main()
{
	cin>>T;
	for(;T--;)
	{
		int N,M,K;
		cin>>N>>M>>K;
		bool flag=false;
		if(N%2==0)
		{
			if(M%2==0)
			{
				flag=K%2==0;
			}
			else if(M==1)
			{
				flag=K==0;
			}
			else
			{
				flag=K%2==0&&(N*M/2-K)>=N/2;
			}
		}
		else if(N==1)
		{
			flag=K==M/2;
		}
		else
		{
			flag=(N*M/2-K)%2==0&&K>=M/2;
		}
		cout<<(flag?"YES\n":"NO\n");
	}
}