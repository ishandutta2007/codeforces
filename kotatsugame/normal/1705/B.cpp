#include<iostream>
using namespace std;
int T,N,A[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		long long ans=0;
		long long cnt=0;
		for(int i=0;i<N-1;i++)
		{
			if(A[i]==0)
			{
				if(cnt==0)continue;
				else ans++;
			}
			else
			{
				ans+=A[i];
				cnt+=A[i];
			}
		}
		cout<<ans<<"\n";
	}
}