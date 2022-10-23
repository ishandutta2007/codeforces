#include<iostream>
#include<algorithm>
using namespace std;
int A[300],N;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		sort(A,A+N);
		long long ans=1e18;
		for(int i=0;i+3<=N;i++)
		{
			ans=min(ans,(long long)(A[i+2]-A[i+1])+(long long)(A[i+1]-A[i]));
		}
		cout<<ans<<"\n";
	}
}