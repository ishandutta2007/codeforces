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
struct node{string s;int vl;char operator<(node b) const {return s<b.s;}};
const int N=5005;int n,lp[N][N],dp[N];char ch[N];
inline void solve()
{
	read(n),scanf("%s",ch+1);for(int i=1;i<=n;i++) dp[i]=n-i+1;
	for(int i=1;i<=n;i++) lp[n][i]=lp[i][n]=(ch[n]==ch[i]);
	for(int i=n-1;i;i--) for(int j=n-1;j;j--) if(ch[i]==ch[j]) lp[i][j]=lp[i+1][j+1]+1;else lp[i][j]=0;
	//for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) printf("%d%c",lp[i][j],j==n?'\n':' ');
	for(int i=2;i<=n;i++) for(int j=1;j<i;j++)
	{
		int l=lp[i][j];if(ch[j+l]>ch[i+l]) continue;
		//printf("%d -> %d : %d\n",j,i,l);
		dp[i]=max(dp[j]+n-i+1-l,dp[i]);
	}
	int mx=0;for(int i=1;i<=n;i++) mx=max(mx,dp[i]);
	printf("%d\n",mx);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}