#include<iostream>
using namespace std;
int N,A[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		long long ans=0;
		int r=0;
		for(int l=0;l<N;l++)
		{
			while(r<N&&A[r]>=r-l+1)r++;
			ans+=r-l;
		}
		cout<<ans<<"\n";
	}
}