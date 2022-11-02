//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
const double eps=1e-10;int X,K;double dp[205][205],p,rs=0;
int main()
{
	read(X),read(K),scanf("%lf",&p),p/=100;
	for(int i=0;i<=K;i++) for(int j=X+i;!(j&1);j>>=1,dp[0][i]++);
	for(int i=0;i<K;i++) for(int j=0;j<=K;j++)
		(j?dp[i+1][j-1]+=dp[i][j]*(1-p):p),(j*2<=K?dp[i+1][j*2]+=(dp[i][j]+1)*p:p);
	return printf("%.10lf\n",dp[K][0]),0;
}