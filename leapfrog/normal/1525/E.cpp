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
//
//
///20!
//a[i]-i
const int P=998244353;int n,m,a[50005][25];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
int main()
{
	read(n),read(m);for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) read(a[j][i]);
	int fc=1,ans=0;for(int i=1;i<=n;i++) fc=1ll*fc*i%P;
	for(int i=1;i<=m;i++)
	{
		sort(a[i]+1,a[i]+n+1);int rs=1;
		for(int j=1;j<=n;j++) rs=1ll*rs*max(a[i][j]-j,0)%P;
		ans=(P+1+ans-1ll*rs*ksm(fc)%P)%P;
	}
	return printf("%d\n",ans),0;
}