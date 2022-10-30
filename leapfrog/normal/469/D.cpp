//Coded by leapfrog on 2021.10.28 {{{
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
const int N=200005;map<int,int>mp;int n,A,B,rs[N],a[N];
struct edge{int to,nxt;}e[N<<2];int et,head[N];
inline void Adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void adde(int x,int y) {Adde(x,y),Adde(y^1,x^1);}
int dfn[N],low[N],dt,st[N],tp,vs[N],cl[N],clt;
inline void tarjan(int x)
{
	dfn[x]=low[x]=++dt,st[++tp]=x,vs[x]=1;
	for(int i=head[x];i;i=e[i].nxt)
		if(!dfn[e[i].to]) tarjan(e[i].to),low[x]=min(low[e[i].to],low[x]);
		else if(vs[e[i].to]) low[x]=min(low[x],dfn[e[i].to]);
	if(low[x]==dfn[x]) {int y;++clt;do vs[y=st[tp--]]=0,cl[y]=clt;while(y^x);}
}
int main()
{
	read(n,A,B);for(int i=1,x;i<=n;i++) read(x),mp[x]=i,a[i]=x;
	for(int i=1;i<=n;i++)
	{
		if(mp[A-a[i]]) adde(i<<1,mp[A-a[i]]<<1);else Adde(i<<1,i<<1|1);
		if(mp[B-a[i]]) adde(i<<1|1,mp[B-a[i]]<<1|1);else Adde(i<<1|1,i<<1);
	}
	for(int i=2;i<=(n<<1|1);i++) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=n;i++) if(cl[i<<1]==cl[i<<1|1]) return puts("NO"),0;
	puts("YES");for(int i=1;i<=n;i++) printf("%d%c",cl[i<<1]>cl[i<<1|1],i==n?'\n':' ');
	return 0;
}