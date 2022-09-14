#include<iostream>
using namespace std;
int T,N,A[100];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		cout<<A[0]<<"\n";
	}
}