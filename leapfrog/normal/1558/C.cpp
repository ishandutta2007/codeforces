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
int n,a[100005],rs[400005],rt;
inline void solve()
{
	read(n),rt=0;for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) if((a[i]&1)^(i&1)) return puts("-1"),void();
	for(int i=n;i>=3;i-=2)
	{
		int wh=1;for(int j=1;j<=i;j++) if(a[j]==i) {wh=j;break;}
		rs[++rt]=wh,reverse(a+1,a+wh+1);
		for(int j=1;j<=i;j++) if(a[j]==i-1) {wh=j;break;}
		rs[++rt]=wh-1,reverse(a+1,a+wh);
		rs[++rt]=wh+1,reverse(a+1,a+wh+2);
		rs[++rt]=3,reverse(a+1,a+3+1);
		rs[++rt]=i,reverse(a+1,a+i+1);
	}
	for(int i=1;i<=n;i++) if(a[i]!=i) return puts("-1"),void();
	printf("%d\n",rt);for(int i=1;i<=rt;i++) printf("%d%c",rs[i],i==rt?'\n':' ');
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}