#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
string text[maxn];
string s[maxn];
int cnt,n;
map<string,int> mp;
char T[maxn];
int main()
{
	string tmp;
	cin>>tmp;
	while(tmp!="\\begin{thebibliography}{99}")
	{
		if(tmp[0]=='\\'&&tmp[1]=='c')
		{
			++cnt;
			int p=0;
			while(tmp[p]!='{')p++;
			p++;
			while(tmp[p]!='}')text[cnt].push_back(tmp[p]),p++;
		}
		cin>>tmp;
	}
	while(tmp!="\\end{thebibliography}")
	{
		//cout<<tmp<<endl;
		string tmp2;tmp2.clear();
		if(tmp[0]=='\\'&&tmp[2]!='e')
		{
			++n;
			s[n]=tmp;
			int p=0;
			while(tmp[p]!='{')p++;
			p++;
			while(tmp[p]!='}')tmp2.push_back(tmp[p]),p++;
			mp[tmp2]=n;
		}
		cin.getline(T,1000);
		int len=strlen(T);
		tmp.clear();
		for(int i=0;i<len;++i)tmp.push_back(T[i]);
	}
	bool ok=1;
	for(int i=1;i<=cnt;++i)
	{
		//cout<<mp[text[i]]<<endl;
		if(mp[text[i]]!=i)ok=0;
	}
	if(ok)puts("Correct");
	else
	{
		puts("Incorrect");
		puts("\\begin{thebibliography}{99}");
		for(int i=1;i<=n;++i)cout<<s[mp[text[i]]]<<endl;
		puts("\\end{thebibliography}");
	}
	return 0;
}