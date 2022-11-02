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
const int P=998244353,p=P-1;int n,fc[1000005],fi[1000005],res=0;
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline int C(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}
int main()
{
	read(n),fc[0]=1;for(int i=1;i<=n;i++) fc[i]=1ll*fc[i-1]*i%P;
	fi[n]=ksm(fc[n]);for(int i=n;i;i--) fi[i-1]=1ll*fi[i]*i%P;
	for(int i=1;i<=n;i++) res=(res+(i&1?P-1ll:1ll)*C(n,i)%P*ksm(3,1ll*(p-i)*n%p)%P*(ksm(P+1-ksm(3,i-n+p),n)-1))%P;
	res=1ll*res*ksm(3,1ll*n*n%p+1)%P,res=(res+2ll*ksm(3,1ll*n*n%p)%P*(ksm(P+1-ksm(3,p-n+1),n)-1)%P)%P;
	return printf("%d\n",(P-res)%P),0;
}