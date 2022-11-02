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
const int N=505;int n,m,P,F[N][N],G[N][N];
int fc[N],fi[N],iv[N];//dbinit{{{
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void dbinit(int n=N-1)
{
	fc[0]=1;for(int i=1;i<=n;i++) fc[i]=1ll*fc[i-1]*i%P;
	iv[1]=1;for(int i=2;i<=n;i++) iv[i]=1ll*iv[P%i]*(P-P/i)%P;
	fi[0]=1;for(int i=1;i<=n;i++) fi[i]=1ll*fi[i-1]*iv[i]%P;
}
inline int C(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}//}}}
inline int gtg(int n,int m) {return 2ll*(n+1-m)*ksm((n+1)<<1,m-1)%P;}//
inline int S(int x) {return 1ll*x*(x+1)/2%P;}
int main()
{
	read(n,m,P),dbinit();for(int i=0;i<=n;i++) G[i][0]=1;
	for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) G[i][j]=gtg(i,j);
	for(int i=1;i<=n;i++)
	{
		int &rs=F[i][i];rs=0;for(int k=1;k<=i;k++)
		{
			rs=(rs+1ll*G[k-1][k-1]*G[i-k][i-k]%P*C(i-1,k-1)%P*(S(k-1)+S(i-k)))%P;
			rs=(rs+(1ll*F[k-1][k-1]*G[i-k][i-k]+1ll*G[k-1][k-1]*F[i-k][i-k])%P*(i+1)%P*C(i-1,k-1))%P;
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<i;j++)
	{
		int &rs=F[i][j];rs=F[i-1][j];for(int k=1;k<=j;k++)
			rs=(rs+(1ll*F[i-k-1][j-k]*G[k][k]+1ll*F[k][k]*G[i-k-1][j-k])%P*C(j,k))%P;
	}
	return printf("%d\n",F[n][m]),0;
}