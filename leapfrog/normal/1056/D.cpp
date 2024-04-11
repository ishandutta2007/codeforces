//Coded by leapfrog on 2021.11.05 {{{
//
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
const int N=100005;int n,sn[N];vector<int>e[N];
inline void dfs(int x) {sn[x]=e[x].empty();for(auto y:e[x]) dfs(y),sn[x]+=sn[y];}
int main()
{
	read(n);for(int i=2,f;i<=n;i++) read(f),e[f].push_back(i);
	dfs(1),sort(sn+1,sn+n+1);for(int i=1;i<=n;i++) printf("%d%c",sn[i],i==n?'\n':' ');
	return 0;
}