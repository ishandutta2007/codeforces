#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<vector>
using namespace std;
const int p=131;
string s,t;
int n,has[111111],pw[111111],k,ha,l[111111],pp[111111],ans;
bool len[111111];
map<int,pair<int,int> > mp;
vector<int> v[111111];
int main()
{
	ios::sync_with_stdio(false);
	cin>>s;
	pw[0]=1;
	for (int i=1;i<=s.size();i++) pw[i]=pw[i-1]*p;
	for (int i=1;i<=s.size();i++)
	{
		has[i]=has[i-1]*p+s[i-1];
	}
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>k>>t;
		len[t.size()]=1;
		ha=0;
		for (int j=0;j<t.size();j++)
		{
			ha=ha*p+t[j];
		}
		mp[ha]=make_pair(k,i);
		l[i]=k;
		pp[i]=t.size();
	}
	for (int i=1;i<=s.size();i++)
	{
		if (!len[i]) continue;
		for (int j=i;j<=s.size();j++)
		{
			ha=has[j]-has[j-i]*pw[i];
			if (mp.find(ha)!=mp.end()) 
			{
				v[mp[ha].second].push_back(j-i);
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (v[i].size()<l[i])
		{
			cout<<-1<<endl;
			continue;
		}
		ans=1e9;
		for (int j=0;j<=v[i].size()-l[i];j++)
		{
			ans=min(ans,v[i][l[i]+j-1]-v[i][j]+pp[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}