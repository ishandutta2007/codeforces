//
//
#include<bits/stdc++.h>
#define int long long
using namespace std;const int P=1e9+9;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,a,b,k,s[100005];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline int zk() {char c=getchar();while(c!='+'&&c!='-') c=getchar();return c=='+'?1:-1;}
signed main()
{
	read(n),read(a),read(b),read(k);int iva=ksm(a),gb=1ll*iva*b%P;
	for(int i=0;i<k;i++) s[i]=((i?s[i-1]:0)+1ll*zk()*ksm(a,n-i)*ksm(b,i)%P+P)%P;
	int tot=(n+1)/k,qaq,q=ksm(gb,k);if(q==1) qaq=tot;
	else qaq=1ll*(ksm(q,tot)-1)*ksm(q-1)%P;
	return printf("%lld\n",1ll*qaq*s[k-1]%P),0;
}