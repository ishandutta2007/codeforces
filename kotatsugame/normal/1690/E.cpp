#include<iostream>
#include<algorithm>
using namespace std;
int T,N,K;
int A[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>K;
		long long ans=0;
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			ans+=A[i]/K;
			A[i]%=K;
		}
		sort(A,A+N);
		int l=0;
		for(int r=N-1;r>l;r--)
		{
			while(l<r&&A[l]+A[r]<K)l++;
			if(l<r)
			{
				l++;
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
}