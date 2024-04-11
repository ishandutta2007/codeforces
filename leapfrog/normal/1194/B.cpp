//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
int n,m,ln[400005],cr[400005];char *ch[400005],$[800005];
inline void solve()
{
	read(n),read(m),ch[1]=$;int ml=0,mc=0,fg=0;for(int i=1;i<=m;i++) cr[i]=0;
	for(int i=1;i<=n;i++) scanf("%s",ch[i]+1),ch[i+1]=ch[i]+m,ln[i]=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(ch[i][j]=='*') ln[i]++,cr[j]++;
	for(int i=1;i<=n;i++) ml=max(ml,ln[i]);
	for(int i=1;i<=m;i++) mc=max(mc,cr[i]);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(ch[i][j]=='.'&&ln[i]==ml&&cr[j]==mc) fg=1;
	printf("%d\n",n+m-ml-mc-fg);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}