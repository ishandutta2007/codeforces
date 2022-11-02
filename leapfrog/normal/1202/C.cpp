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
int n,X[200005],Y[200005],dx[205],dy[205];char ch[200005];
inline int getfs(int *a,int vl) {for(int i=0;i<=n;i++) if(a[i]==vl) return i;}
inline int getls(int *a,int vl) {for(int i=n;i>=0;i--) if(a[i]==vl) return i;}
inline void solve()
{
	scanf("%s",ch+1),n=strlen(ch+1);
	for(int i=1;i<=n;i++) X[i]=X[i-1]+dx[(int)ch[i]],Y[i]=Y[i-1]+dy[(int)ch[i]];
	int mnx=0,mxx=0;for(int i=1;i<=n;i++) mnx=min(mnx,X[i]),mxx=max(mxx,X[i]);
	int mny=0,mxy=0;for(int i=1;i<=n;i++) mny=min(mny,Y[i]),mxy=max(mxy,Y[i]);
	ll rs=1ll*(mxx-mnx+1)*(mxy-mny+1);
	if(getfs(X,mnx)-getls(X,mxx)>1||getfs(X,mxx)-getls(X,mnx)>1) rs=min(rs,1ll*(mxx-mnx)*(mxy-mny+1));
	if(getfs(Y,mny)-getls(Y,mxy)>1||getfs(Y,mxy)-getls(Y,mny)>1) rs=min(rs,1ll*(mxx-mnx+1)*(mxy-mny));
	printf("%lld\n",rs);
}
int main() {int Ca;for(dx['W']=dy['A']=-1,dx['S']=dy['D']=1,read(Ca);Ca--;) solve();return 0;}