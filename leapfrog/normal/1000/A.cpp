//Coded by Kamiyama_Shiki on 2021.11.10 {{{
//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
map<string,int>mp;int n;string s;
int main()
{
	read(n);for(int i=1;i<=n;i++) cin>>s,mp[s]++;
	int rs=n;for(int i=1;i<=n;i++) cin>>s,(mp[s]?rs--,mp[s]--:0);
	return printf("%d\n",rs),0;
}