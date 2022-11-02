#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
const int N=505,P=998244353;
int fc[N],fi[N],iv[N];//dbinit{{{
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void dbinit(int n=N-1)
{
    fc[0]=1;for(int i=1;i<=n;i++) fc[i]=1ll*fc[i-1]*i%P;
    iv[1]=1;for(int i=2;i<=n;i++) iv[i]=1ll*iv[P%i]*(P-P/i)%P;
    fi[0]=1;for(int i=1;i<=n;i++) fi[i]=1ll*fi[i-1]*iv[i]%P;
}
inline int C(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}//}}}
int n,K,dp[N][N];
inline int dfs(int x,int w)
{
	if(x==0) return 1;else if(x==1) return 0;
	if(dp[x][w]) return dp[x][w];
	int &rs=dp[x][w];if(w<x) return ksm(w,x);
	for(int i=0;i<=x;i++) rs=(rs+1ll*dfs(x-i,w-x+1)*ksm(x-1,i)%P*C(x,i))%P;
	return rs;
}
int main()
{
	read(n,K),dbinit(),dp[1][n]=1;
	printf("%d\n",dfs(n,K));
}