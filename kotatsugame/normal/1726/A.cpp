#include<iostream>
#include<algorithm>
using namespace std;
int N,A[2000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		int ans=-1e9;
		if(N==1)
		{
			cout<<"0\n";
			continue;
		}
		ans=max(ans,A[N-1]-*min_element(A,A+N-1));
		ans=max(ans,*max_element(A+1,A+N)-A[0]);
		for(int i=0;i<N;i++)
		{
			ans=max(ans,A[(i+N-1)%N]-A[i]);
		}
		cout<<ans<<"\n";
	}
}