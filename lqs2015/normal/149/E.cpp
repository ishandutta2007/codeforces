#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str[111111],tp[111111];
string s,sr,t,tr;
int n,m,ans,ts,fail[1111],sp[1111],z[1111],f[1111];
int next(char c,int j,string &s)
{
	for (;j!=-1 && s[j]!=c;j=fail[j]);
	return j+1;
}
void kmp_process(string &s)
{
	memset(fail,0,sizeof(fail));
	fail[0]=-1;
	int f=0;
	for (int i=1;i<s.size();i++)
	{
		fail[i]=f;
		if (s[i]==s[fail[i]] && fail[fail[i]]!=-1) fail[i]=fail[fail[i]];
		f=next(s[i],f,s);
	}
}
void kmp_match(string &s,string &sk)
{
	memset(sp,-1,sizeof(sp));
	int j=0;
	for (int i=0;i<s.size();i++)
	{
		j=next(s[i],j,sk);
		if (sp[j]==-1) sp[j]=i;
	}
}
int main()
{
	scanf("%s",str);
	n=strlen(str);
	for (int i=0;i<n;i++)
	{
		s+=str[i];
	}
	for (int i=n-1;i>=0;i--)
	{
		sr+=str[i];
	}
	scanf("%d",&m);
	while(m--)
	{
		scanf("%s",tp);
		ts=strlen(tp);
		tr=t="";
		for (int i=0;i<ts;i++)
		{
			t+=tp[i];
			tr+=tp[ts-1-i];
		}
		kmp_process(t);
		kmp_match(s,t);
		for (int i=1;i<=ts;i++) 
		{
			z[i]=sp[i];
		}
		kmp_process(tr);
		kmp_match(sr,tr);
		for (int i=1;i<=ts;i++) 
		{
			if (sp[i]==-1) f[i]=-1;
			else f[i]=n-1-sp[i];
		}
		for (int i=1;i<ts;i++)
		{
			if (z[i]!=-1 && z[i]<f[ts-i])
			{
				ans++;
				break;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}