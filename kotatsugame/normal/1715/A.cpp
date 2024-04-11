#include<iostream>
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
		cout<<(N==1&&M==1?0:N+M-2+min(N,M))<<"\n";
	}
}