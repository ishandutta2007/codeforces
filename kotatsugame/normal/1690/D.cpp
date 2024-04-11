#include<iostream>
using namespace std;
int T,N,K;
string S;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>K>>S;
		int cnt=0;
		int ans=1e9;
		for(int i=0;i<N;i++)
		{
			if(S[i]=='W')cnt++;
			if(i>=K&&S[i-K]=='W')cnt--;
			if(i>=K-1)ans=min(ans,cnt);
		}
		cout<<ans<<"\n";
	}
}