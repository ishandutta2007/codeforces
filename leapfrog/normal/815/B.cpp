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
const int P=1e9+7;int n,a[200005],fc[200005],fi[200005];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void init()
{
	fc[0]=1;for(int i=1;i<=200000;i++) fc[i]=1ll*fc[i-1]*i%P;
	fi[200000]=ksm(fc[200000]);for(int i=200000;i;i--) fi[i-1]=1ll*fi[i]*i%P;
}
inline int C(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}
int main()
{
	read(n),init();for(int i=1;i<=n;i++) read(a[i]);
	if(n==1) return printf("%d\n",a[1]),0;
	if(n&1) {n--;for(int i=1;i<=n;i++) if(i&1) a[i]=(a[i]+a[i+1])%P;else a[i]=(a[i]-a[i+1]+P)%P;}
	int tag,ds=n>>1,rs=0;ds--;if((n>>1)&1) tag=1;else tag=P-1;
	for(int i=1;i<=n;++++i) rs=(rs+1ll*a[i]*C(ds,i>>1)+1ll*tag*a[i+1]%P*C(ds,i>>1))%P;
	return printf("%d\n",rs),0;
}