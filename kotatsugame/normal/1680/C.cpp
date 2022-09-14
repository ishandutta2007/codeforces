#include<iostream>
using namespace std;
int T;
string S;
int cnt[2<<17];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>S;
		cnt[0]=0;
		for(int i=0;i<S.size();i++)cnt[i+1]=cnt[i]+(S[i]-'0');
		int ans=1e9;
		for(int j=0;j<=S.size();j++)
		{
			if(j>=cnt[S.size()])ans=min(ans,cnt[S.size()]-cnt[j]+cnt[j-cnt[S.size()]]);
		}
		cout<<ans<<"\n";
	}
}