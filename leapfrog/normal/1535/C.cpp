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
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=200005;int n,a[N];char ch[N];
inline void solve()
{
	scanf("%s",ch+1),n=strlen(ch+1);ll rs=0;int nw=-1,cn=0,r=1;
	for(int i=1;i<=n;i++) if(ch[i]=='?') a[i]=-1;else a[i]=ch[i]^48^(i&1);
	for(;r<=n&&(nw==-1||a[r]==-1||a[r]==nw);r++) if(~a[r]) nw=a[r],cn++;
	for(int l=1;l<=n;l++)
	{
		rs+=r-l;if(~a[l]&&--cn==0) nw=-1;
		for(;r<=n&&(nw==-1||a[r]==-1||a[r]==nw);r++) if(~a[r]) nw=a[r],cn++;
	}printf("%lld\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}