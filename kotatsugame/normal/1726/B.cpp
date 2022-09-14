#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N,M;
		cin>>N>>M;
		if(N>M)
		{
			cout<<"No\n";
			continue;
		}
		if(N%2==1)
		{
			cout<<"Yes\n";
			for(int i=0;i<N-1;i++)cout<<"1 ";
			cout<<M-(N-1)<<"\n";
		}
		else
		{
			if(M%2==1)
			{
				cout<<"No\n";
				continue;
			}
			cout<<"Yes\n";
			for(int i=0;i<N-2;i++)cout<<"1 ";
			M-=N-2;
			cout<<M/2<<" "<<M/2<<"\n";
		}
	}
}