#include<iostream>
using namespace std;
int N,K;
int P[100];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N>>K;
		for(int i=0;i<N;i++)cin>>P[i];
		int ans=0;
		for(int i=0;i<K;i++)if(P[i]>K)ans++;
		cout<<ans<<"\n";
	}
}