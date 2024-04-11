//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
int n,m;map<int,int>mp;vector<int>v;
int main()
{
	read(n,m);for(int i=1,x;i<=n;i++) read(x),mp[x]=1;
	for(int i=1;i<=1e9;i++) if(!mp[i]) {if(m<i) break;else v.push_back(i),m-=i;}
	printf("%d\n",(int)v.size());for(auto x:v) printf("%d ",x);
	return putchar('\n'),0;
}