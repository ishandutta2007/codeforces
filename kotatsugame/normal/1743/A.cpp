#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;cin>>N;
		for(int i=0;i<N;i++)
		{
			int t;cin>>t;
		}
		N=10-N;
		cout<<N*(N-1)/2*6<<"\n";
	}
}