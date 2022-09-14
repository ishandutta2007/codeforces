#include<iostream>
using namespace std;
int N;
int A[5050];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	long long ans=9e18;
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=0;i<N;i++)
	{
		long long now=0;
		{
			long long prv=0;
			for(int j=i+1;j<N;j++)
			{
				long long t=prv/A[j]+1;
				now+=t;
				prv=t*A[j];
			}
		}
		{
			long long prv=0;
			for(int j=i-1;j>=0;j--)
			{
				long long t=prv/A[j]+1;
				now+=t;
				prv=t*A[j];
			}
		}
		if(ans>now)ans=now;
	}
	cout<<ans<<endl;
}