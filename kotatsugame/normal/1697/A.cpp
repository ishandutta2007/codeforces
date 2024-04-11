#include<iostream>
using namespace std;
int T,N,M;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M;
		for(int i=0;i<N;i++)
		{
			int a;cin>>a;
			M-=a;
		}
		cout<<(M<0?-M:0)<<"\n";
	}
}