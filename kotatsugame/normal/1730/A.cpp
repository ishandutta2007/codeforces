#include<iostream>
using namespace std;
int cnt[101];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		for(int i=0;i<=100;i++)cnt[i]=0;
		int N,C;
		cin>>N>>C;
		for(int i=0;i<N;i++)
		{
			int a;cin>>a;
			cnt[a]++;
		}
		int ans=0;
		for(int i=0;i<=100;i++)ans+=min(cnt[i],C);
		cout<<ans<<"\n";
	}
}