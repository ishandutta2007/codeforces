#include<iostream>
#include<map>
using namespace std;
int n;
string s;
pair<int,int>p[1<<17];
map<pair<int,int>,int>M;
main()
{
	cin>>n;
	for(int cnt=0;cnt<n;cnt++)
	{
		cin>>s;
		int c=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='(')
			{
				c++;
			}
			else
			{
				if(c>0)c--;
				else p[cnt].first++;
			}
		}
		c=0;
		for(int i=s.size();i--;)
		{
			if(s[i]==')')
			{
				c++;
			}
			else
			{
				if(c>0)c--;
				else p[cnt].second++;
			}
		}
		M[p[cnt]]++;
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(p[i].first>0&&p[i].second>0)continue;
		if(M[p[i]]==0)continue;
		M[p[i]]--;
		pair<int,int>q;
		if(p[i].first>0)q.first=0,q.second=p[i].first;
		else q.second=0,q.first=p[i].second;
		if(M[q]>0)
		{
			M[q]--;
			ans++;
		}
	}
	cout<<ans<<endl;
}