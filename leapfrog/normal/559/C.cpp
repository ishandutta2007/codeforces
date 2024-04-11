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
const int W=400005,P=1e9+7;
int fc[W],fi[W],iv[W];//dbinit{{{
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void dbinit(int n)
{
	fc[0]=1;for(int i=1;i<=n;i++) fc[i]=1ll*fc[i-1]*i%P;
	iv[1]=1;for(int i=2;i<=n;i++) iv[i]=1ll*iv[P%i]*(P-P/i)%P;
	fi[0]=1;for(int i=1;i<=n;i++) fi[i]=1ll*fi[i-1]*iv[i]%P;
}
inline int C(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}//}}}
int n,F[2005];pair<int,int>p[2005];
int main()
{
	read(p[0].first,p[0].second,n);for(int i=1;i<=n;i++) read(p[i].first,p[i].second);
	dbinit(W-4),sort(p,p+n+1);for(int i=0;i<=n;i++) F[i]=C(p[i].first+p[i].second-2,p[i].first-1);
	for(int i=0;i<=n;i++) for(int j=0;j<i;j++) if(i^j)
	{
		if(p[i].first<p[j].first||p[i].second<p[j].second) continue;
		F[i]=(F[i]-1ll*F[j]*C(p[i].first-p[j].first+p[i].second-p[j].second,p[i].first-p[j].first)%P+P)%P;
	}
	return printf("%d\n",F[n]),0;
}