//Coded by Kamiyama_Shiki on 2021.11.05 {{{
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
const int N=705;int n,a[N],w[N][N],dp[N][N][2];
inline int gcd(int x,int y) {return y?gcd(y,x%y):x;}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) w[i][j]=gcd(a[i],a[j]);
	for(int i=1;i<=n;i++) dp[i][i-1][0]=dp[i+1][i][1]=1;
	for(int ln=0;ln<n;ln++) for(int l=1,r=l+ln;r<=n;l++,r++)
		for(int k=l;k<=r;k++) if(dp[l][k-1][0]&&dp[k+1][r][1])
		{
			if(l==1&&r==n) return puts("Yes"),0;
			if(l!=1&&w[k][l-1]!=1) dp[l][r][1]=1;
			if(r!=n&&w[k][r+1]!=1) dp[l][r][0]=1;
		}
	return puts("No"),0;
}