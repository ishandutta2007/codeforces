#include<bits/stdc++.h>
using namespace std;
string s[10001];
int main()
{
	int n,m=0;
	cin>>n;
	for(int x=1;x<=n;x++)cin>>s[x];
	char t;
	cin>>t;
	for(int x=1;x<=n;x++)s[x]+=t,m+=s[x].size();
	m/=n/2;
	sort(s+1,s+1+n);
	for(int x=1;x<=n;x++)
	for(int y=x+1;y<=n;y++)
	if(s[x].size()+s[y].size()==m)cout<<s[x],s[y]=s[y].substr(0,s[y].length()-1),cout<<s[y]<<endl,s[x]="",s[y]="",y=n+1;
}