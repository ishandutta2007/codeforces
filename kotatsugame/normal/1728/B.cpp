#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;
		cin>>N;
		if(N%2==0)
		{
			for(int i=N-2;i>=1;i--)cout<<i<<" ";
			cout<<N-1<<" "<<N<<"\n";
		}
		else
		{
			cout<<"1 ";
			for(int i=N-2;i>=2;i--)cout<<i<<" ";
			cout<<N-1<<" "<<N<<"\n";
		}
	}
}