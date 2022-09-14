#include<iostream>
using namespace std;
int T,N,A[10101];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		bool f=false;
		for(int i=1;i<N;i++)if(A[i-1]>A[i])f=true;
		cout<<(f?"YES\n":"NO\n");
	}
}