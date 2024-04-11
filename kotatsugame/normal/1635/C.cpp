#include<iostream>
using namespace std;
int T,N;
int A[2<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		if(A[N-1]<0)
		{
			bool ok=true;
			for(int i=1;i<N;i++)if(A[i-1]>A[i])ok=false;
			cout<<(ok?"0\n":"-1\n");
			continue;
		}
		if(A[N-2]>A[N-1])
		{
			cout<<"-1\n";
			continue;
		}
		cout<<N-2<<"\n";
		for(int i=N-3;i>=0;i--)
		{
			cout<<i+1<<" "<<i+2<<" "<<N<<"\n";
		}
	}
}