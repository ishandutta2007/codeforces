#include<iostream>
using namespace std;
int T,N,K;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>K;
		if(K==1)
		{
			cout<<"YES\n";
			for(int i=1;i<=N;i++)cout<<i<<"\n";
		}
		else if(N%2==1)
		{
			cout<<"NO\n";
		}
		else
		{
			cout<<"YES\n";
			int f=0;
			for(int i=0;i<N/2;i++)
			{
				for(int j=0;j<K;j++)
				{
					f+=2;
					cout<<f<<(j+1==K?"\n":" ");
				}
			}
			f=-1;
			for(int i=0;i<N/2;i++)
			{
				for(int j=0;j<K;j++)
				{
					f+=2;
					cout<<f<<(j+1==K?"\n":" ");
				}
			}
		}
	}
}