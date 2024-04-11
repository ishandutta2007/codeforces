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
int n,m,K,a[2000005][5];
inline int qwq(int x,int y)
{
	int vl=0;for(int j=0;j<5;j++) vl+=a[x][j]<a[y][j];
	return vl<3?y:x;
}
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) for(int j=0;j<5;j++) read(a[i][j]);
	int rs=1;for(int i=2;i<=n;i++) rs=qwq(rs,i);
	for(int i=1;i<=n;i++) if(qwq(rs,i)!=rs) return puts("-1"),void();
	printf("%d\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}