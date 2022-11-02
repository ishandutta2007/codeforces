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
int n,a[100005];ll f[100005],rs;map<int,ll>mp;
inline void solve()
{
	read(n),mp.clear(),rs=0;for(int i=1;i<=n;i++) f[i]=0,read(a[i]);
	for(int i=1;i<=n;i++) f[i]=f[i-1]+mp[a[i]],mp[a[i]]+=i,rs+=f[i];
	printf("%lld\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}