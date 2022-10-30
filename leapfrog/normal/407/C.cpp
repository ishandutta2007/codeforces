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
const int N=500005,P=1e9+7;
int n,m,a[100005],v[105][100005];
int fc[N],fi[N],iv[N];//dbinit{{{
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void dbinit(int n)
{
	fc[0]=1;for(int i=1;i<=n;i++) fc[i]=1ll*fc[i-1]*i%P;
	iv[1]=1;for(int i=2;i<=n;i++) iv[i]=1ll*iv[P%i]*(P-P/i)%P;
	fi[0]=1;for(int i=1;i<=n;i++) fi[i]=1ll*fi[i-1]*iv[i]%P;
}
inline int C(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}//}}}
int main()
{
	read(n,m);for(int i=1;i<=n;i++) read(a[i]);
	dbinit(N-5);for(int i=1,l,r,k;i<=m;i++)
	{
		read(l,r,k),v[k][l]++;if(r==n) continue;
		for(int j=k;j>=0;j--) v[j][r+1]=(v[j][r+1]+P-C(r-l+k-j,k-j))%P;
	}
	//for(int k=3;k>=0;k--) for(int i=1;i<=n;i++) printf("%d%c",v[k][i],i==n?'\n':' ');
	for(int k=101;k>=1;k--)
	{
		for(int i=1;i<=n;i++) v[k][i]=(v[k][i-1]+v[k][i])%P;
		for(int i=1;i<=n;i++) v[k-1][i]=(v[k-1][i]+v[k][i])%P;
	}
	for(int i=1;i<=n;i++) v[0][i]=(v[0][i-1]+v[0][i])%P;
	for(int i=1;i<=n;i++) printf("%d%c",(v[0][i]+a[i])%P,i==n?'\n':' ');
	return 0;
}