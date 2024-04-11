//Coded by leapfrog on 2021.10.29 {{{
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
const int N=1005;int as[N],at,dis;vector<int>d[N];
struct edge{int to,nxt;}e[N<<1];int n,et,head[N],rx,fg[N];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline pair<int,int> ask()
{
	printf("? %d ",at);for(int i=1;i<=at;i++) printf("%d%c",as[i],i==at?'\n':' ');
	fflush(stdout);int u,v;read(u,v);return make_pair(u,v);
}
inline void answer(int x,int y)
{
	printf("! %d %d\n",x,y),fflush(stdout);char ch[10];
	scanf("%s",ch);if(*ch=='I') exit(0);
}
inline void dfs0(int x,int fa,int dep,int rt)
{
	d[dep].push_back(x),fg[x]=rt;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs0(e[i].to,x,dep+1,rt);
}
inline char check(int w)
{
	if(d[w].empty()) return 0;else at=d[w].size();
	for(int i=1;i<=at;i++) as[i]=d[w][i-1];
	pair<int,int>q=ask();if(q.second==dis) return rx=q.first,1;else return 0;
}
inline void solve()
{
	read(n),et=0;for(int i=1;i<=n;i++) head[i]=fg[i]=0;
	for(int i=1,x,y;i<n;i++) read(x,y),adde(x,y),adde(y,x);
	at=n;for(int i=1;i<=n;i++) as[i]=i,d[i].clear();
	pair<int,int>q=ask();int rt=q.first;dis=q.second;
	int l=(dis+1)/2,r=n,rs=r;d[1].push_back(rt);
	for(int i=head[rt];i;i=e[i].nxt) dfs0(e[i].to,rt,2,e[i].to);
	while(l<=r) {int md=(l+r)>>1;if(check(md)) rs=md,l=md+1;else r=md-1;}
	int ds=dis-rs+2;at=0;
	for(size_t i=0;i<d[ds].size();i++) if(fg[d[ds][i]]^fg[rx]) as[++at]=d[ds][i];
	q=ask(),answer(rx,q.first);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}