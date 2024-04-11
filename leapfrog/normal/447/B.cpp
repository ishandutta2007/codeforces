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
char ch[1005];int K,vl[26];
int main()
{
	scanf("%s",ch+1),read(K);for(int i=0;i<26;i++) read(vl[i]);
	int n=strlen(ch+1);int rs=0,mx=0;
	for(int i=0;i<26;i++) mx=max(mx,vl[i]);
	for(int i=1;i<=n;i++) rs+=i*vl[ch[i]-'a'];
	for(int i=1;i<=K;i++) rs+=(i+n)*mx;
	return printf("%d\n",rs),0;
}