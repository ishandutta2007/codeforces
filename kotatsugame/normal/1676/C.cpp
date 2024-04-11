#include<iostream>
using namespace std;
int T;
int N,M;
string S[50];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M;
		for(int i=0;i<N;i++)cin>>S[i];
		int ans=1e9;
		for(int i=0;i<N;i++)for(int j=i+1;j<N;j++)
		{
			int now=0;
			for(int k=0;k<M;k++)
			{
				int a=S[i][k],b=S[j][k];
				if(a>b)swap(a,b);
				now+=b-a;
			}
			ans=min(ans,now);
		}
		cout<<ans<<"\n";
	}
}