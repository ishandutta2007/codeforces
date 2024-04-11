//Coded by Kamiyama_Shiki on 2021.10.31 {{{
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
const int N=200005;
struct edge{int to,nxt;}e[N<<1];int et,head[N],dg[N],n,rs;
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et,dg[x]++;}
inline int dfs(int x,int fa)
{
	vector<int>v;for(int i=head[x];i;i=e[i].nxt)
		if(e[i].to!=fa) v.push_back(dfs(e[i].to,x));
	sort(v.begin(),v.end());
	if(v.empty()) return 1;else rs=max(rs,v[0]);
	if(v.size()==1ull) return v[0]+1;
	if(fa) rs=max(rs,v.back()+1);else rs=max(rs,max(v[v.size()-2]+1,v.back()));
	return v[0]+1;
}
inline void solve()
{
	read(n),et=0,memset(head,0,sizeof(head)),memset(dg,0,sizeof(dg));
	for(int i=1,x,y;i<n;i++) read(x,y),adde(x,y),adde(y,x);
	rs=0,dfs(1,0),printf("%d\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}