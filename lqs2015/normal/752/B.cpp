#include<iostream>
#include<string>
#include<vector>
using namespace std;
string s,t;
char a[26],ans1[111],ans2[111];
int ans;
int main()
{
	cin>>s>>t;
	for (int i=0;i<26;i++) a[i]='&';
	for (int i=0;i<s.size();i++)
	{
		if ((a[s[i]-'a']!='&' && a[s[i]-'a']!=t[i]) 
		|| (a[t[i]-'a']!='&' && a[t[i]-'a']!=s[i]))
		{
			cout<<-1<<endl;
			return 0;
		}
		else 
		{
			a[s[i]-'a']=t[i];
			a[t[i]-'a']=s[i];
		}
	}
	for (int i=0;i<26;i++)
	{
		if (a[i]!='&' && i<a[i]-'a')
		{
			ans++;
			ans1[ans]=i+'a';
			ans2[ans]=a[i];
		}
	}
	cout<<ans<<endl;
	for (int i=1;i<=ans;i++)
	{
		cout<<ans1[i]<<" "<<ans2[i]<<endl;
	}
	return 0;
}