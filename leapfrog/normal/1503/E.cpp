//Coded by leapfrog on 2021.10.29 {{{
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
const int N=4045,P=998244353;int n,m;
int fc[N],fi[N],iv[N];//dbinit{{{
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void dbinit(int n=N-1)
{
	fc[0]=1;for(int i=1;i<=n;i++) fc[i]=1ll*fc[i-1]*i%P;
	iv[1]=1;for(int i=2;i<=n;i++) iv[i]=1ll*iv[P%i]*(P-P/i)%P;
	fi[0]=1;for(int i=1;i<=n;i++) fi[i]=1ll*fi[i-1]*iv[i]%P;
}
inline int C(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}//}}}
inline int count(int x,int y) {return C(x+y,x);}
int main()
{
	read(n,m),dbinit();int rs=0;
	for(int i=1,qz=0;i<m;i++,qz=0) for(int j=1;j<n;j++)
	{
		qz=(qz+1ll*count(i,j-1)*count(i-1,n-j))%P;
		rs=(rs+1ll*qz*count(m-i-1,j)%P*count(m-i,n-j-1))%P;
	}swap(n,m);
	for(int i=1,qz=0;i<m;i++,qz=0) for(int j=1;j<n;j++)
	{
		rs=(rs+1ll*qz*count(m-i-1,j)%P*count(m-i,n-j-1))%P;
		qz=(qz+1ll*count(i,j-1)*count(i-1,n-j))%P;
	}swap(n,m);
	return printf("%d\n",(rs<<1)%P),0;
}