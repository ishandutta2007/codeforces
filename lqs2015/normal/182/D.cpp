#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;
const int p=131;
int z[111111];
void z_function(string &s)
{
	int l,r,j,sz;
	z[0]=0;l=r=0;
	sz=s.size();
	for (int i=1;i<sz;i++)
	{
		if (i>r)
		{
			for (j=0;j<sz-i;j++)
			{
				if (s[j]!=s[i+j]) break;
			}
			l=i;r=i+j-1;z[i]=j;
		}
		else
		{
			int k=i-l;
			if (z[k]<r-i+1)
			{
				z[i]=z[k];
			}
			else
			{
				for (j=r-i;j<sz-i;j++)
				{
					if (s[j]!=s[i+j]) break;
				}
				l=i;r=i+j-1;z[i]=j;
			}
		}
	}
}
char s[111111],ss[111111];
string s1,s2;
int hash1[111111],hash2[111111],ans;
bool f1[111111],f2[111111];
int main()
{
	gets(s);gets(ss);
	int sis=strlen(s),siss=strlen(ss);
	for (int i=0;i<sis;i++) s1+=s[i];
	for (int i=0;i<siss;i++) s2+=ss[i];
	hash1[0]=s1[0];
	for (int i=1;i<s1.size();i++)
	{
		hash1[i]=hash1[i-1]*p+s1[i];
	}
	hash2[0]=s2[0];
	for (int i=1;i<s2.size();i++)
	{
		hash2[i]=hash2[i-1]*p+s2[i];
	}
	z_function(s1);
	for (int i=1;i<s1.size();i++)
	{
		if (z[i]+i==s1.size() && s1.size()%i==0) f1[i]=1;
	}
	f1[s1.size()]=1;
	z_function(s2);
	for (int i=1;i<s2.size();i++)
	{
		if (z[i]+i==s2.size() && s2.size()%i==0) f2[i]=1;
	}
	f2[s2.size()]=1;
	for (int i=1;i<=s1.size() && i<=s2.size();i++)
	{
		if (f1[i] && f2[i] && hash1[i-1]==hash2[i-1]) ans++;
	}
	cout<<ans<<endl;
	return 0;
}