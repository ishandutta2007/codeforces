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
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
int n,m,a[1005][1005],fa[1000005],cn[1000005],tn[1000005];ll K;
map<int,int>mp;vector<pair<int,int> >v[1000005];char vs[1005][1005];
#define ID(x,y) (((x)-1)*m+(y))
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline void mrg(int x,int y) {x=getf(x),y=getf(y);if(x^y) fa[x]=y,cn[y]+=cn[x];}
inline void out(int vl,int x,int y)
{
	queue<pair<int,int> >q;q.push(make_pair(x,y));int gg=tn[vl],g=K/gg;
	while(!q.empty())
	{
		int x=q.front().first,y=q.front().second;q.pop();
		if(!g) break;else if(vs[x][y]) continue;else g--,vs[x][y]=1;
		if(x-1>=1&&cn[ID(x-1,y)]&&!vs[x-1][y]) q.push(make_pair(x-1,y));
		if(x+1<=n&&cn[ID(x+1,y)]&&!vs[x+1][y]) q.push(make_pair(x+1,y));
		if(y-1>=1&&cn[ID(x,y-1)]&&!vs[x][y-1]) q.push(make_pair(x,y-1));
		if(y+1<=m&&cn[ID(x,y+1)]&&!vs[x][y+1]) q.push(make_pair(x,y+1));
	}puts("YES");
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) printf("%d%c",vs[i][j]?gg:0,j==m?'\n':' ');
}
signed main()
{
	read(n,m,K);for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) read(a[i][j]),mp[a[i][j]]=1;
	int id=0;for(auto&x:mp) tn[x.second=++id]=x.first;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) v[mp[a[i][j]]].push_back(make_pair(i,j));
	for(int i=id;i>=1;i--) for(auto t:v[i])
	{
		int x=t.first,y=t.second;fa[ID(x,y)]=ID(x,y),cn[ID(x,y)]++;
		if(x-1>=1&&fa[ID(x-1,y)]) mrg(ID(x,y),ID(x-1,y));
		if(x+1<=n&&fa[ID(x+1,y)]) mrg(ID(x,y),ID(x+1,y));
		if(y-1>=1&&fa[ID(x,y-1)]) mrg(ID(x,y),ID(x,y-1));
		if(y+1<=m&&fa[ID(x,y+1)]) mrg(ID(x,y),ID(x,y+1));
		//printf("ins %d %d and cnt is %d\n",x,y,cn[id]);
		//for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) printf("%d%c",getf(ID(i,j)),j==m?'\n':' ');
		//for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) printf("%d%c",cn[getf(ID(i,j))],j==m?'\n':' ');
		int id=getf(ID(x,y));if(K%tn[i]==0&&1ll*cn[id]*tn[i]>=K) return out(i,x,y),0;
	}
	return puts("NO"),0;
}