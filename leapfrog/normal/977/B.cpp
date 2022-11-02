#include <bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
template<typename T,typename... A>inline void read(T &t,A &...a) {read(t),read(a...);}
int n,mx;string s,t;map<string,int>mp;
signed main()
{
	read(n),cin>>s;
	for(int i=0;i<n-1;i++) {string g;g+=s[i],g+=s[i+1],mp[g]++;}
	for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++) if(it->second>mx) mx=it->second,t=it->first;
	return cout<<t<<endl,0;
}