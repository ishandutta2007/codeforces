#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;int h[30];
int main()
{
	int T,i;cin>>T;
	while (T--)
	{
		cin>>s;
		for (i=0;i<26;i++) h[i]=0;
		for (i=0;i<s.length();i++) h[s[i]-'a']++;
		for (i=0;i<s.length();i++) {if (h[s[i]-'a']==1) break;h[s[i]-'a']--;}
		for (;i<s.length();i++) putchar(s[i]);puts("");
	}
}