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
const int P=998244353;int n,fc[100005],fi[100005];char ch[100005];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void init()
{
	fc[0]=1;for(int i=1;i<=100000;i++) fc[i]=1ll*fc[i-1]*i%P;
	fi[100000]=ksm(fc[100000]);for(int i=100000;i;i--) fi[i-1]=1ll*fi[i]*i%P;
}
inline int C(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}
inline void solve()
{
	read(n),scanf("%s",ch+1);
	int a=n,b=0,nw=0;for(int i=1;i<=n;i++)
		if(ch[i]=='1') nw++,(nw==2?(nw=0,b++):0);
		else a-=nw,nw=0;
	(nw?(a-=nw,nw=0):0),printf("%d\n",C(a-b,b));
}
int main() {int Ca;for(init(),read(Ca);Ca--;) solve();return 0;}