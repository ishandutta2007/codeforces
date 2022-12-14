#include<bits/stdc++.h>
using namespace std;
string s,t;
int fail[555555],n0,n1,pos;
int kmp_next(char c,int j)
{
	for (;j!=-1 && s[j]!=c;j=fail[j]);
	return j+1;
}
void kmp_process()
{
	fail[0]=-1;
	int f=0;
	for (int i=1;i<s.size();i++)
	{
		fail[i]=f;
		if (s[fail[i]]==s[i] && fail[fail[i]]!=-1) fail[i]=fail[fail[i]];
		f=kmp_next(s[i],f);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>t>>s;
	s.push_back('*');
	kmp_process();
	for (int i=0;i<t.size();i++) 
	{
		if (t[i]=='0') n0++;
		else n1++;
	} 
	pos=0;
	while(1)
	{
		if (s[pos]=='*') pos=fail[pos];
		if (s[pos]=='0')
		{
			if (!n0) break;
			putchar('0');
			pos++;n0--;
		}
		else
		{
			if (!n1) break;
			putchar('1');
			pos++;n1--;
		}
	}
	for (int i=1;i<=n0;i++) putchar('0');
	for (int i=1;i<=n1;i++) putchar('1');
	return 0;
}