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
int Ca,n,m,K,a[1000005];char ch[1000005];
inline void solve()
{
	read(n),scanf("%s",ch+1);char fg=1;
	for(int i=1,e=n>>1;i<=e;i++) if(abs(ch[i]-ch[n+1-i])>2||abs(ch[i]-ch[n+1-i])%2) fg=0;
	if(fg) puts("YES");else puts("NO");
}
int main() {for(read(Ca);Ca--;) solve();return 0;}