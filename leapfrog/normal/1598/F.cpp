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
const int N=21;
int n,dp[(1<<N)+N],sm[(1<<N)+N],tn[21][400005],mn[N+4];string s[N+5];
int main()
{
	read(n);for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++)
	{//tn:k
		int nw=0,mn=0,cn=0;
		for(auto x:s[i])
		{
			if(x=='(') nw++;else nw--;
			if(nw<mn) mn=nw,cn=1;else if(mn==nw) cn++;
			tn[i][-mn]=cn;
		}
		sm[1<<(i-1)]=nw,::mn[i]=mn;
	}memset(dp,~0x3f,sizeof(dp)),dp[0]=0;int rs=0;
	for(int S=1;S<(1<<n);S++) sm[S]=sm[S&(-S)]+sm[S^(S&(-S))];
	for(int S=0;S<(1<<n);S++) if(sm[S]>=0&&dp[S]>=0)
		for(int i=0;i<n;i++) if(!((S>>i)&1))
		{
			if(sm[S]+mn[i+1]<0) rs=max(rs,dp[S]+tn[i+1][sm[S]]);
			else dp[S|(1<<i)]=max(dp[S|(1<<i)],dp[S]+tn[i+1][sm[S]]);
		}
	for(int i=0;i<(1<<n);i++) rs=max(rs,dp[i]);
	return printf("%d\n",rs),0;
}