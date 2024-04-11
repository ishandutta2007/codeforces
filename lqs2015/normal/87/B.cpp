#include<iostream>
#include<map>
#include<cstdio>
#include<string>
using namespace std;
map<string,pair<int,int> > mp;
int n,cnt1,cnt2;
string tp,s1,s2,s;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	while(n--)
	{
		cin>>tp;
		if (tp=="typedef")
		{
			cin>>s1>>s2;
			s="";
			cnt1=cnt2=0;
			for (int i=0;i<s1.size();i++)
			{
				if (s1[i]=='&') cnt1++;
				else if (s1[i]=='*') cnt2++;
				else s+=s1[i];
			}
			if (s=="void")
			{
				if (cnt2-cnt1<0) mp[s2]=make_pair(0,0);
				else mp[s2]=make_pair(1,cnt2-cnt1);
				continue;
			}
			if (mp.find(s)==mp.end() || !mp[s].first)
			{
				mp[s2]=make_pair(0,0);
			}
			else
			{
				if (mp[s].second+cnt2-cnt1<0) mp[s2]=make_pair(0,0);
				else mp[s2]=make_pair(1,mp[s].second+cnt2-cnt1);
			}
		}
		else
		{
			cin>>s1;
			s="";
			cnt1=cnt2=0;
			for (int i=0;i<s1.size();i++)
			{
				if (s1[i]=='&') cnt1++;
				else if (s1[i]=='*') cnt2++;
				else s+=s1[i];
			}
			if (s=="void") 
			{
				cout<<s1<<endl;
				continue;
			}
			if (mp.find(s)==mp.end() || !mp[s].first || mp[s].second+cnt2-cnt1<0)
			{
				cout<<"errtype"<<endl;
				continue;
			}
			cout<<"void";
			for (int i=1;i<=mp[s].second+cnt2-cnt1;i++)
			cout<<"*";
			cout<<endl;
		}
	}
	return 0;
}