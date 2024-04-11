#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T;
main()
{
	cin>>T;
	for(;T--;)
	{
		string s;cin>>s;
		vector<int>G[26];
		for(int i=1;i<s.size();i++)
		{
			int u=s[i-1]-'a';
			int v=s[i]-'a';
			G[u].push_back(v);
			G[v].push_back(u);
		}
		bool out=false;
		for(int i=0;i<26;i++)
		{
			sort(G[i].begin(),G[i].end());
			G[i].erase(unique(G[i].begin(),G[i].end()),G[i].end());
			if(G[i].size()>=3)
			{
				out=true;
			}
		}
		if(out)
		{
			cout<<"NO"<<endl;
			continue;
		}
		string ans="";
		vector<bool>used(26,false);
		for(int i=0;i<26;i++)
		{
			if(G[i].size()==0)
			{
				ans+=(char)(i+'a');
				used[i]=true;
			}
		}
		for(int i=0;i<26;i++)
		{
			if(used[i]||G[i].size()!=1)continue;
			ans+=(char)(i+'a');
			used[i]=true;
			int now=G[i][0];
			int pre=i;
			while(!used[now])
			{
				used[now]=true;
				ans+=(char)(now+'a');
				if(G[now].size()==1)break;
				else if(G[now].size()==2)
				{
					if(G[now][0]==pre)
					{
						pre=now;
						now=G[now][1];
					}
					else
					{
						pre=now;
						now=G[now][0];
					}
				}
			}
		}
		if(ans.size()!=26)
		{
			cout<<"NO"<<endl;
			continue;
		}
		bool ok=true;
		for(int i=0;i<26;i++)
		{
			for(int v:G[ans[i]-'a'])
			{
				ok&=i>0&&ans[i-1]-'a'==v||i<25&&ans[i+1]-'a'==v;
			}
		}
		if(ok)
		{
			cout<<"YES"<<endl;
			cout<<ans<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
}