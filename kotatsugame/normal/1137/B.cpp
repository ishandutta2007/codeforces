#line 1 "a.cpp"
#include<iostream>
using namespace std;
#line 1 "/home/kotatsugame/library/string/Zalgo.cpp"
//Longest Common Prefix(s,s.substr(i)) O(|s|)
#include<vector>
#include<string>
vector<int>Zalgo(const string&s)
{
	vector<int>ret(s.size());
	if(s.empty())return ret;
	ret[0]=s.size();
	int i=1,j=0;
	while(i<s.size())
	{
		while(i+j<s.size()&&s[j]==s[i+j])j++;
		ret[i]=j;
		if(j==0)
		{
			i++;
			continue;
		}
		int k=1;
		while(i+k<s.size()&&k+ret[k]<j)ret[i+k]=ret[k],k++;
		i+=k;j-=k;
	}
	return ret;
}
#line 4 "a.cpp"
string s,t;
main()
{
	cin>>s>>t;
	int s0=0,s1=0;
	for(char c:s)
	{
		if(c=='0')s0++;
		else s1++;
	}
	int t0=0,t1=0;
	for(char c:t)
	{
		if(c=='0')t0++;
		else t1++;
	}
	vector<int>ret=Zalgo(t);
	int id=1;
	while(id<ret.size()&&id+ret[id]<t.size())id++;
	int tt0=t0,tt1=t1;
	for(int i=id;i<t.size();i++)
	{
		if(t[i]=='0')tt0--;
		else tt1--;
	}
	if(t0>s0||t1>s1)
	{
		cout<<s<<endl;
		return 0;
	}
	string ans=t;
	s0-=t0;
	s1-=t1;
	while(s0>=tt0&&s1>=tt1)
	{
		int L=(int)t.size()-id;
		for(int k=L;k<t.size();k++)ans+=t[k];
		s0-=tt0;
		s1-=tt1;
	}
	for(int i=0;i<s0;i++)ans+='0';
	for(int i=0;i<s1;i++)ans+='1';
	cout<<ans<<endl;
}