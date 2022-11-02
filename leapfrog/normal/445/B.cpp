//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=55;int n,m,vs[N];vector<int>e[N];
inline void dfs(int x) {vs[x]=1;for(auto y:e[x]) if(!vs[y]) dfs(y);}
int main()
{
	read(n,m);for(int i=1,x,y;i<=m;i++) read(x,y),e[x].push_back(y),e[y].push_back(x);
	int cnt=n;for(int i=1;i<=n;i++) if(!vs[i]) cnt--,dfs(i);
	return printf("%lld\n",1ll<<cnt),0;
}