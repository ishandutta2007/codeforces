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
const int N=100005;
int Ca,n,m,K,a[N];char s[N];
inline char chk(int x,int y,int z)
{
	for(int i=1;i<=n;i++) if(s[i]=='A') a[i]=x;else if(s[i]=='B') a[i]=y;else a[i]=z;
	int nw=0;for(int i=1;i<=n;i++) {nw+=a[i];if(nw<0) return 0;}
	return !nw;
}
inline void solve()
{
	scanf("%s",s+1),n=strlen(s+1);int tag=0;
	for(int i=-1;i<=1;i+=2) for(int j=-1;j<=1;j+=2) for(int k=-1;k<=1;k+=2) if(chk(i,j,k)) tag=1;
	if(tag) puts("YES");else puts("NO");
}
int main() {for(read(Ca);Ca--;) solve();return 0;}