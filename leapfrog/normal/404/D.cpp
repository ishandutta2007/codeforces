//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
const int P=1000000007;
int n,dp[1000005][3];char ch[1000005];//0,1,2,*,?
inline int pl(int a,int b) {return (a+=b)>=P?a-P:a;}
inline void pls(int &a,int b) {(a+=b)>=P?a-=P:0;}
int main()
{
	scanf("%s",ch+1),n=strlen(ch+1);
	if(ch[1]=='?') dp[0][0]=dp[0][1]=1;else if(ch[1]=='*') dp[0][1]=1;else dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		if(ch[i]=='0'||ch[i]=='?') pls(dp[i][0],dp[i-1][0]);
		if(ch[i]=='1'||ch[i]=='?') pls(dp[i][0],dp[i-1][2]),pls(dp[i][1],dp[i-1][0]);
		if(ch[i]=='2'||ch[i]=='?') pls(dp[i][1],dp[i-1][2]);
		if(ch[i]=='*'||ch[i]=='?') pls(dp[i][2],pl(dp[i-1][1],dp[i-1][2]));
	}
	return printf("%d\n",pl(dp[n][0],dp[n][2])),0;
}