#include<bits/stdc++.h>
using namespace std;
vector<int>v;string s;int k;
int main()
{
	ios::sync_with_stdio(false),cin>>s>>k;
	for(int i=0;i<(int)s.size();i++) v.push_back(s[i]-'0');
	for(int i=1;i<=k;i++)
	{
		if(!s.size()) return puts("0"),0;
		if(v.back()) v.back()--;else v.pop_back();
	}
	for(int i=0;i<(int)v.size();i++) printf("%d",v[i]);
	return putchar('\n'),0;
}