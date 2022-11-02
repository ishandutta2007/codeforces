#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;int g=0,n;
signed main()
{
	ios::sync_with_stdio(false),cin>>s,n=s.length();
	for(int i=0;i<n;i++) {if(i!=n-1&&s[i]=='v'&&s[i+1]=='v') g++;if(i!=0&&s[i]=='v'&&s[i-1]=='v') g++;}
	g/=2;int cnt=0,ans=0;
	for(int i=0;i<n;i++)
	{
		if(i!=n-1&&s[i]=='v'&&s[i+1]=='v') cnt++;
		if(i!=0&&s[i]=='v'&&s[i-1]=='v') cnt++;
		if(s[i]=='o') ans+=(cnt>>1)*(g-(cnt>>1));
	}
	return printf("%lld\n",ans),0;
}