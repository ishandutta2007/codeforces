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
int n,dp[26][26];char ch[10005];
int main()
{
	memset(dp,~0x3f,sizeof(dp)),read(n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",ch+1);int l=strlen(ch+1),a=ch[1]-'a',b=ch[l]-'a';
		for(int j=0;j<26;j++) dp[j][b]=max(dp[j][a]+l,dp[j][b]);
		dp[a][b]=max(dp[a][b],l);
	}int rs=0;for(int i=0;i<26;i++) rs=max(rs,dp[i][i]);
	return printf("%d\n",rs),0;
}