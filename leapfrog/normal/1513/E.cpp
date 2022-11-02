//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int n,a[100005],fc[100005],fi[100005];ll sm=0;const int P=1e9+7;map<int,int>p,q,t;int cn=0,c1=0,c2=0;
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline int C(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),sm+=a[i];
	fc[0]=1;for(int i=1;i<=n+3;i++) fc[i]=1ll*fc[i-1]*i%P;
	fi[n+3]=ksm(fc[n+3]);for(int i=n+3;i;i--) fi[i-1]=1ll*fi[i]*i%P;
	if(sm%n) return puts("0"),0;else sm/=n;
	for(int i=1;i<=n;i++) if(a[i]==sm) cn++;
	for(int i=1;i<=n;i++) if(a[i]<sm) p[a[i]]++,c1++;
	for(int i=1;i<=n;i++) if(a[i]>sm) q[a[i]]++,c2++;
	if(!c1||!c2) return puts("1"),0;else if(c1==1||c2==1)
	{
		int cn=0,sm=1;for(int i=1;i<=n;i++) t[a[i]]++;
		for(auto x:t) sm=1ll*sm*fi[x.second]%P,cn+=x.second;
		return printf("%lld\n",1ll*fc[cn]*sm%P),0;
	}
	int res=2ll*C(n,cn)%P,sm,cn;
	sm=1,cn=0;for(auto x:p) sm=1ll*sm*fi[x.second]%P,cn+=x.second;
	res=1ll*res*fc[cn]%P*sm%P;
	sm=1,cn=0;for(auto x:q) sm=1ll*sm*fi[x.second]%P,cn+=x.second;
	res=1ll*res*fc[cn]%P*sm%P;
	return printf("%d\n",res),0;
}