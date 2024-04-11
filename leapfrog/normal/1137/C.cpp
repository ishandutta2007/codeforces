//Coded by Kamiyama_Shiki on 2021.11.19 {{{
//
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=5000005;int n,m,d,tmp[N];ll sta[100005];
struct edge{int to,nxt;}e[N];int et,head[N];vector<int>E[N];int dg[N];
inline int ID(int x,int k) {return k*n+x;}
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
int dfn[N],low[N],dt,st[N],tp,cl[N],clt,cn[N],rs[N];char vs[N],in[N],vp[N];
inline void tarjan(int x)
{
	dfn[x]=low[x]=++dt,vs[st[++tp]=x]=1;
	for(int i=head[x];i;i=e[i].nxt)
		if(!dfn[e[i].to]) tarjan(e[i].to),low[x]=min(low[x],low[e[i].to]);
		else if(vs[e[i].to]) low[x]=min(low[x],dfn[e[i].to]);
	if(dfn[x]==low[x])
	{
		int y,pmt=0;++clt;do vs[tmp[++pmt]=y=st[tp--]]=0,cl[y]=clt;while(y^x);
		for(int i=1,x,a;i<=pmt;i++) {x=tmp[i];if((sta[a=(x-1)%n+1]>>((x-1)/n))&1) cn[clt]+=!vp[a],vp[a]=1;}
		for(int i=1;i<=pmt;i++) vp[(tmp[i]-1)%n+1]=0;
	}
}
int main()
{
	read(n,m,d);for(int i=1,x,y;i<=m;i++) {read(x,y);for(int j=0;j<d;j++) adde(ID(x,j),ID(y,(j+1)%d));}
	for(int i=1;i<=n;i++) {scanf("%s",in);for(int j=0;j<d;j++) if(in[j]^48) sta[i]|=1ll<<j;}
	memset(rs,~0x3f,sizeof(rs));for(int i=1;i<=d*n;i++) if(!dfn[i]) tarjan(i);
	for(int x=1;x<=d*n;x++) for(int i=head[x];i;i=e[i].nxt) if(cl[x]^cl[e[i].to]) E[cl[x]].push_back(cl[e[i].to]),dg[cl[e[i].to]]++;
	queue<int>q;rs[cl[ID(1,0)]]=cn[cl[ID(1,0)]];for(int i=1;i<=clt;i++) if(!dg[i]) q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(auto y:E[x]) {rs[y]=max(rs[y],rs[x]+cn[y]);if(!--dg[y]) q.push(y);}
	}
	int res=0;for(int i=1;i<=clt;i++) res=max(res,rs[i]);
	return printf("%d\n",res),0;
}