#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200002];
signed main()
{
	string s,t;
	cin>>s>>t;
	s=' '+s,t=' '+t;
	for(int x=1;x<t.size();x++)
	a[x]=a[x-1]+(t[x]=='1');
	int ans=0;
	for(int x=1;x<s.size();x++) //{
	ans+=(s[x]=='1')*(t.size()-s.size()+1-a[t.size()-s.size()+x]+a[x-1])+(s[x]=='0')*(a[t.size()-s.size()+x]-a[x-1]);
	//cout<<t.size()-s.size()+1-a[t.size()-s.size()+x]+a[x-1]<<','<<a[t.size()-s.size()+x]-a[x-1]<<',';
	cout<<ans<<endl;//}
}