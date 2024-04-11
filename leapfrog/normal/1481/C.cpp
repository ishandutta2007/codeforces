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
int T,n,m,K,a[100005],b[100005],c[100005],v[100005],r[100005];vector<int>cl[100005];
inline void solve()
{
	read(n),read(m),memset(v,0,sizeof(v));for(int i=1;i<=n;i++) cl[i].clear();
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) read(b[i]);
	for(int i=1;i<=m;i++) read(c[i]);
	for(int i=1;i<=n;i++) if(a[i]^b[i]) cl[b[i]].push_back(i);
	for(int i=1;i<=n;i++) v[b[i]]=i;
	for(int i=m,fg=0;i;i--)
	{
		if(cl[c[i]].empty()&&!fg&&!v[c[i]]) return puts("NO"),void();
		if(cl[c[i]].empty()&&!fg) {fg=r[i]=v[c[i]];continue;}
		if(cl[c[i]].empty()) {r[i]=fg;continue;}
		fg=r[i]=cl[c[i]].back(),cl[c[i]].pop_back();
	}
	for(int i=1;i<=n;i++) if(!cl[i].empty()) return puts("NO"),void();
	puts("YES");for(int i=1;i<=m;i++) printf("%d%c",r[i],i==m?'\n':' ');
}
int main() {for(read(T);T--;) solve();return 0;}