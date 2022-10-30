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
const int N=2000005,P=1e9+7;
int fc[N],fi[N],iv[N];//dbinit{{{
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void dbinit(int n)
{
    fc[0]=1;for(int i=1;i<=n;i++) fc[i]=1ll*fc[i-1]*i%P;
    iv[1]=1;for(int i=2;i<=n;i++) iv[i]=1ll*iv[P%i]*(P-P/i)%P;
    fi[0]=1;for(int i=1;i<=n;i++) fi[i]=1ll*fi[i-1]*iv[i]%P;
}
inline int C(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}//}}}
int n,A[15],F[65536],a[1000005],b[1000005];
int main()
{
	read(n),dbinit(N-1);for(int i=0;i<n;i++) read(A[i]);
	for(int S=1;S<(1<<n);S++)
	{
		F[S]=1;for(int T=(S-1)&S;T;T=(T-1)&S)
		{
			int at=0,bt=0;for(int i=0;i<n;i++) if((S>>i)&1) ((T>>i)&1?a[++at]:b[++bt])=i;
			int qwq=1;for(int i=1;i<=at;i++) for(int j=1;j<=bt;j++)
				qwq=1ll*qwq*A[a[i]]%P*iv[A[a[i]]+A[b[j]]]%P;
			F[S]=(F[S]-1ll*qwq*F[T]%P+P)%P;
		}
	}
	int rs=0;for(int S=1;S<(1<<n);S++)
	{
		int at=0,bt=0;for(int i=0;i<n;i++) (((S>>i)&1)?a[++at]:b[++bt])=i;
		int qwq=1;for(int i=1;i<=at;i++) for(int j=1;j<=bt;j++)
			qwq=1ll*qwq*A[a[i]]%P*iv[A[a[i]]+A[b[j]]]%P;
		rs=(rs+1ll*qwq%P*F[S]%P*at)%P;
	}
	return printf("%d\n",rs),0;
}