#include<bits/stdc++.h>
using namespace std;
int a[1005],point=0;
int main()
{
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<'a') s[i]=s[i]-'A'+'a';
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!='a'&&s[i]!='e'&&s[i]!='y'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u')
			a[point++]=s[i];
	}
	for(int i=0;i<point;i++) cout<<'.'<<(char)a[i];
	cout<<endl;
	return 0;
}