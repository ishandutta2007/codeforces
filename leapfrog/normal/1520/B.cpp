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
int Ca,n;
inline ll get(int v,int k) {ll r=0;for(int i=1;i<=v;i++) r=r*10+k;return r;}
inline void solve()
{
	read(n);int cnt=0;
	for(int i=1;i<=9;i++) for(int k=1;k<10;k++) if(get(i,k)<=n) cnt++;
	printf("%d\n",cnt);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}