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
int Ca,n,a[200005],mx[200005],mn[200005];set<int>s1,s2;
inline void solve()
{
	read(n),s1.clear(),s2.clear(),a[0]=-1e9;
	for(int i=1;i<=n;i++) read(a[i]),s1.insert(i),s2.insert(i);
	for(int i=1;i<=n;i++) if(a[i]^a[i-1]) s1.erase(a[i]),s2.erase(a[i]),mx[i]=mn[i]=a[i];
	for(int i=1;i<=n;i++) if(a[i]==a[i-1])
	{
		mx[i]=*--s1.lower_bound(a[i]),s1.erase(mx[i]);
		mn[i]=*s2.upper_bound(0),s2.erase(mn[i]);
	}
	for(int i=1;i<=n;i++) printf("%d%c",mn[i],i==n?'\n':' ');
	for(int i=1;i<=n;i++) printf("%d%c",mx[i],i==n?'\n':' ');
}
int main() {for(read(Ca);Ca--;) solve();return 0;}