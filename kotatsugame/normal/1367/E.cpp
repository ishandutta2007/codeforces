#include<iostream>
#include<algorithm>
using namespace std;
int cnt[26];
string s;
int T,N,K;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>K>>s;
		for(int i=0;i<26;i++)cnt[i]=0;
		int ans=0;
		for(char c:s)
		{
			cnt[c-'a']++;
			if(ans<cnt[c-'a'])ans=cnt[c-'a'];
		}
		for(int k=1;k<=K;k++)if(K%k==0)
		{
			for(int t=1;;t++)
			{
				int now=0;
				for(int i=0;i<26;i++)now+=cnt[i]/t;
				if(now<k)break;
				ans=max(ans,k*t);
			}
		}
		cout<<ans<<endl;
	}
}