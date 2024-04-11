#include<iostream>
using namespace std;
int T,N;
int cA[26],cB[26],cC[26][26];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		for(int i=0;i<26;i++)
		{
			cA[i]=cB[i]=0;
			for(int j=0;j<26;j++)cC[i][j]=0;
		}
		cin>>N;
		long long ans=0;
		for(int i=0;i<N;i++)
		{
			string s;cin>>s;
			int a=s[0]-'a',b=s[1]-'a';
			ans+=cA[a]+cB[b]-cC[a][b]*2;
			cA[a]++;
			cB[b]++;
			cC[a][b]++;
		}
		cout<<ans<<"\n";
	}
}