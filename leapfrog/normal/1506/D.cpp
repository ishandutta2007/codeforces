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
int Ca,n,a[200005];map<int,int>mp;
inline void solve()
{
	read(n),mp.clear();for(int i=1;i<=n;i++) read(a[i]),mp[a[i]]++;
	int mx=0;for(auto x:mp) mx=max(mx,x.second);
	int qw=max(mx*2-n,0);if(n&1) qw|=1;
	printf("%d\n",qw);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}