#include<iostream>
using namespace std;
int T;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		int N;cin>>N;
		for(int i=1;i<=N;i++)
		{
			cout<<(i==2?3:i==3?2:i)<<(i==N?"\n":" ");
		}
		for(int t=2;t<=N;t++)
		{
			for(int i=1;i<N;i++)
			{
				int now=(t+i-3)%(N-1)+2;
				cout<<now<<" ";
			}
			cout<<"1\n";
		}
	}
}