//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
const int P=1e9+7;int n,K,fc[10005],fi[10005],rs=0,pw1[10005],pw2[10005];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline int C(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}
int main()
{
	read(n),read(K),fc[0]=1;for(int i=1;i<=n;i++) fc[i]=1ll*fc[i-1]*i%P;
	fi[n]=ksm(fc[n]);for(int i=n;i;i--) fi[i-1]=1ll*fi[i]*i%P;
	pw1[0]=pw2[0]=1;for(int i=1;i<=n;i++) pw1[i]=1ll*pw1[i-1]*K%P,pw2[i]=1ll*pw2[i-1]*(K-1)%P;
	for(int i=0;i<=n;i++) rs=(rs+(i&1?P-1ll:1ll)*C(n,i)%P*ksm(1ll*pw1[n-i]*pw2[i]%P-pw2[n]+P,n))%P;
	return printf("%d\n",(rs+P)%P),0;
}