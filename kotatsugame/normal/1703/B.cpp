#include<iostream>
using namespace std;
string S;
bool ex[26];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	for(;T--;)
	{
		int N;cin>>N>>S;
		for(int i=0;i<26;i++)ex[i]=false;
		int ans=0;
		for(int i=0;i<N;i++)
		{
			int t=S[i]-'A';
			if(!ex[t])ex[t]=true,ans++;
			ans++;
		}
		cout<<ans<<"\n";
	}
}