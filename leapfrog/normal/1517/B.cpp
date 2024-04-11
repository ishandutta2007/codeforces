//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}int Ca;
int n,m,b[105][105],id[105],ed[105],a[105][105];set<pair<int,int> >st;
inline void solve()
{
	read(n),read(m),st.clear();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) read(b[i][j]);
	for(int i=1;i<=n;i++) sort(b[i]+1,b[i]+m+1),id[i]=1,ed[i]=m,st.insert(make_pair(b[i][1],i));
	ll res=0;for(int i=1;i<=m;i++)
	{
		pair<int,int>x=*st.begin();st.erase(st.begin()),a[x.second][i]=b[x.second][id[x.second]++];
		res+=x.first;for(int j=1;j<=n;j++) if(j^x.second) a[j][i]=b[j][ed[j]--];
		if(id[x.second]<=ed[x.second]) st.insert(make_pair(b[x.second][id[x.second]],x.second));
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) printf("%d%c",a[i][j],j==m?'\n':' ');
}
int main() {for(read(Ca);Ca--;) solve();return 0;}