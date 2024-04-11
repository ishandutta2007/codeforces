#include<iostream>
#include<vector>
using namespace std;
int T;
string S;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>S;
		vector<int>cnt(26);
		for(char c:S)cnt[c-'a']++;
		string ans="";
		for(int i=0;i<26;i++)if(cnt[i]==1)
		{
			ans+=i+'a';
			cnt[i]--;
			for(int j=0;j<26;j++)for(int k=0;k<cnt[j];k++)ans+=j+'a';
			break;
		}
		if(ans.size()>0)
		{
			cout<<ans<<"\n";
			continue;
		}
		int mi=0;
		while(cnt[mi]==0)mi++;
		int t=cnt[mi]-1;
		int r=S.size()-cnt[mi]+1;
		if((t+r-1)/r==1)
		{
			ans+=mi+'a';
			cnt[mi]--;
			for(int j=0;j<26;j++)if(j!=mi)for(int k=0;k<cnt[j];k++)
			{
				if(cnt[mi]>0)
				{
					cnt[mi]--;
					ans+=mi+'a';
				}
				ans+=j+'a';
			}
			if(cnt[mi]>0)
			{
				ans+=mi+'a';
			}
			cout<<ans<<"\n";
			continue;
		}
		int mi2=mi+1;
		while(mi2<26&&cnt[mi2]==0)mi2++;
		if(mi2==26)
		{
			for(int k=0;k<cnt[mi];k++)ans+=mi+'a';
			cout<<ans<<"\n";
			continue;
		}
		int mi3=mi2+1;
		while(mi3<26&&cnt[mi3]==0)mi3++;
		if(mi3==26)
		{
			ans+=mi+'a';
			for(int k=0;k<cnt[mi2];k++)ans+=mi2+'a';
			for(int k=1;k<cnt[mi];k++)ans+=mi+'a';
			cout<<ans<<"\n";
			continue;
		}
		ans+=mi+'a';
		ans+=mi2+'a';
		for(int k=1;k<cnt[mi];k++)ans+=mi+'a';
		ans+=mi3+'a';
		cnt[mi]=0;
		cnt[mi2]--;
		cnt[mi3]--;
		for(int j=mi2;j<26;j++)for(int k=0;k<cnt[j];k++)ans+=j+'a';
		cout<<ans<<"\n";
	}
}