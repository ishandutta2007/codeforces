//Coded by Kamiyama_Shiki on 2021.11.03 {{{
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
int n,m,ind[4000005],ds[4000005],to[4000005];char ch[2005][2005],vs[4000005];
inline int ID(int x,int y) {return (x-1)*m+y;}
inline int fndc(int x) {int rt=x,cn=1;x=to[x];while(rt!=x) x=to[x],cn++;return cn;}
inline void fgdc(int x,int vl) {int rt=x;ds[x]=vl,x=to[x];while(rt!=x) ds[x]=vl,x=to[x];}
inline int dfs(int x) {if(ds[x]) return ds[x];else return ds[x]=dfs(to[x])+1;}
inline void solve()
{
	read(n,m);for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	for(int i=1;i<=n*m;i++) to[i]=ind[i]=ds[i]=vs[i]=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
	{
		int nx=i,ny=j,id=ID(i,j);
		if(ch[i][j]=='R') ny++;else if(ch[i][j]=='L') ny--;
		if(ch[i][j]=='D') nx++;else if(ch[i][j]=='U') nx--;
		if(nx<1||nx>n||ny<1||ny>m) ind[id]++,to[id]=id;
		else to[id]=ID(nx,ny),ind[ID(nx,ny)]++;
	}
	queue<int>q;for(int i=1;i<=n*m;i++) if(!ind[i]) q.push(i),vs[i]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		if(!--ind[to[x]]) q.push(to[x]),vs[to[x]]=1;
	}
	int debug=0;for(int i=1;i<=n*m;i++) debug+=vs[i];
	//if(n==2000&&m==2000) return printf("? %d\n",debug),void();
	for(int i=1;i<=n*m;i++) if(!vs[i]&&!ds[i]) fgdc(to[i],fndc(i));
	for(int i=1;i<=n*m;i++) if(vs[i]) dfs(i);
	int ps=1;for(int i=1;i<=n*m;i++) if(ds[i]>ds[ps]) ps=i;
	printf("%d %d %d\n",(ps-1)/m+1,(ps-1)%m+1,ds[ps]);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}