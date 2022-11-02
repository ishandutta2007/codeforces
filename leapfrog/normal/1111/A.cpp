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
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
char s[114514],t[1919810],mp[1005];int n;
int main()
{
	mp['a']=mp['e']=mp['i']=mp['o']=mp['u']=1;
	scanf("%s%s",s+1,t+1);if(strlen(s+1)!=strlen(t+1)) return puts("No"),0;
	for(int i=1;s[i];i++) if(mp[s[i]]^mp[t[i]]) return puts("No"),0;
	return puts("Yes"),0;
}