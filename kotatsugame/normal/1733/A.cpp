#include<iostream>
using namespace std;
int A[100];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N,K;cin>>N>>K;
		for(int i=0;i<K;i++)A[i]=0;
		for(int i=0;i<N;i++)
		{
			int a;cin>>a;
			A[i%K]=max(A[i%K],a);
		}
		long long ans=0;
		for(int i=0;i<K;i++)ans+=A[i];
		cout<<ans<<"\n";
	}
}