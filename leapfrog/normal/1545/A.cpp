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
int n,a[100005],b[100005],cn[100005][2];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),b[i]=a[i];
	for(int i=1;i<=100000;i++) cn[i][0]=cn[i][1]=0;
	sort(b+1,b+n+1);for(int i=1;i<=n;i++) cn[b[i]][i&1]++;
	for(int i=1;i<=n;i++) cn[a[i]][i&1]--;
	for(int i=1;i<=100000;i++) if(cn[i][0]||cn[i][1]) return puts("NO"),void();
	puts("YES");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}