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
int Ca,n,a[100005],v[105];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	memset(v,0,sizeof(v));for(int i=1;i<=n;i++) v[a[i]]++;
	for(int i=0;i<=100;i++) if(v[i]) printf("%d ",i),v[i]--;else break;
	for(int i=0;i<=100;i++) while(v[i]) printf("%d ",i),v[i]--;
	putchar('\n');
}
int main() {for(read(Ca);Ca--;) solve();return 0;}