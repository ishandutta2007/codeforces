#include<iostream>
#include<algorithm>
using namespace std;
int T,N;
int A[70];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		if(N==1)
		{
			cout<<"0\n";
			continue;
		}
		int ans=N;
		for(int i=0;i<N;i++)for(int j=i+1;j<N;j++)
		{
			int d=A[j]-A[i];
			int l=j-i;
			int now=0;
			for(int k=0;k<N;k++)
			{
				if(A[k]*l!=A[i]*l+(k-i)*d)now++;
			}
			ans=min(ans,now);
		}
		cout<<ans<<"\n";
	}
}