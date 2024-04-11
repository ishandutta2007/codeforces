//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
const int N=100005;
int T,n,K,a[N];map<int,char>mp;
inline void solve()
{
	read(n),read(K);for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1),n=unique(a+1,a+n+1)-a-1,a[0]=-1;char tag=0;
	int mx=0,me=0;for(int i=1;i<=n;i++) if(a[i]!=a[i-1]+1) tag=1;
	if(!tag) return printf("%d\n",n+K),void();else mp.clear();
	for(int i=1;i<=n;i++) mp[a[i]]=1,mx=max(mx,a[i]);
	for(int i=0;;i++) if(!mp[i]) {me=i;break;}
	printf("%d\n",n+(!mp[(me+mx+1)>>1]&&K));
}
int main() {for(read(T);T--;) solve();return 0;}