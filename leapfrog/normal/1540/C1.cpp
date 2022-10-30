//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	char ch=getchar(),bz=0;x=0;
	for(;ch<48||ch>57;ch=getchar()) if(!(ch^45)) bz=1;
	for(;ch>=48&&ch<=57;ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	bz?x=-x:0;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
const int P=1e9+7;int n,q,c[105],b[105],X,lm[105],dp[105][10005],s[105][10005];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(c[i]);
	for(int i=1;i<n;i++) read(b[i]);
	read(q),read(X);if(X>100) return puts("0"),0;
	for(int i=1;i<=n;i++) for(int j=1;j<i;j++) lm[i]+=(i-j)*b[j];
	for(int i=1;i<=n;i++) lm[i]+=i*X,lm[i]=max(lm[i],0);
	int m=0;for(int i=1;i<=n;i++) m+=c[i];
	dp[0][0]=0;for(int i=0;i<=m;i++) s[0][i]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=lm[i];j<=m;j++)
		{
			int qw=(j-c[i]-1<0?0:s[i-1][j-c[i]-1]);
			dp[i][j]=(s[i-1][j]-qw+P)%P;
		}
		for(int j=lm[i];j<=m;j++) s[i][j]=(s[i][j-1]+dp[i][j])%P;
	}
	return printf("%d\n",s[n][m]),0;
}