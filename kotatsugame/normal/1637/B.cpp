#include<iostream>
using namespace std;
int T,N,A[100];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		int ans=0;
		for(int l=0;l<N;l++)for(int r=l+1;r<=N;r++)
		{
			for(int i=l;i<r;i++)ans+=1+!A[i];
		}
		cout<<ans<<"\n";
	}
}