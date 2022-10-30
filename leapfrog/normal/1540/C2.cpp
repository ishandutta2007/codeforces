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
const int P=1e9+7;int n,q,m,c[105],b[105],X,lm[105];
int LM[105],dp[105][10005],s[105][10005],rs[505],sc[105];
inline int solve(int X)
{
	for(int i=1;i<=n;i++) {lm[i]=max(LM[i]+i*X,0);if(lm[i]>m) return 0;}
	dp[0][0]=1;for(int i=0;i<=m;i++) s[0][i]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=lm[i];j<=m;j++)
		{
			int ps=j-c[i]-1,qw=(ps<lm[i-1]||ps>m?0:s[i-1][ps]);
			dp[i][j]=((j<lm[i-1]||j>m?0:s[i-1][j])-qw+P)%P;
		}s[i][lm[i]]=dp[i][lm[i]];
		for(int j=lm[i]+1;j<=m;j++) s[i][j]=(s[i][j-1]+dp[i][j])%P;
	}
	return s[n][m];
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(c[i]);
	for(int i=1;i<n;i++) read(b[i]);
	for(int i=1;i<=n;i++) for(int j=1;j<i;j++) LM[i]+=(i-j)*b[j];
	for(int i=1;i<=n;i++) m+=c[i],sc[i]=sc[i-1]+c[i];
	int neg=1;for(int i=1;i<=n;i++) neg=1ll*neg*(c[i]+1)%P;
	int L=1e9,R=1e9;for(int i=1;i<=n;i++) L=min(L,-LM[i]/i)-1,R=min(R,(100*n-LM[i])/i)+1;
	for(int i=L;i<=R;i++) rs[i-L]=solve(i);
	read(q);for(int x;q--;) read(x),printf("%d\n",x<L?neg:(x>R?0:rs[x-L]));
	return 0;
}