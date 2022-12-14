#include<iostream>
#include<string>
#include<set>
using namespace std;
string s;
set<char> se;
void doit(int l,int r)
{
	for (int i=0;i<l;i++)
	{
		if (s[i]=='?') cout<<'A';
		else cout<<s[i];
	}
	bool vis[44];
	for (int i=0;i<26;i++) vis[i]=0;
	for (int i=l;i<=r;i++)
	{
		if (s[i]!='?') vis[s[i]-'A']=1;
	}
	for (int i=l;i<=r;i++)
	{
		if (s[i]=='?')
		{
			for (int j=0;j<26;j++)
			{
				if (!vis[j])
				{
					cout<<(char)(j+'A');
					vis[j]=1;
					break;
				}
			}
		}
		else cout<<s[i];
	}
	for (int i=r+1;i<s.size();i++)
	{
		if (s[i]=='?') cout<<'A';
		else cout<<s[i];
	}
	cout<<endl;
}
int main()
{
	cin>>s;
	if (s.size()<26) 
	{
		cout<<-1<<endl;
		return 0;
	}
	int n=s.size();
	for (int i=0;i<n-25;i++)
	{
		int e=i+25;
		bool f=0;
		se.clear();
		for (int j=i;j<=e;j++)
		{
			if (s[j]!='?')
			{
				if (se.find(s[j])!=se.end()) f=1;
				se.insert(s[j]);
			}
		}
		if (!f)
		{
			doit(i,e);
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}