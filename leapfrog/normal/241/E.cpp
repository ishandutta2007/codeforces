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
int n,m,ds[1005],ff[5005],tt[5005];char vs[1005],fg[1005];
vector<int>e1[1005];int fr[10005],tw[10005],we[10005],et;
inline char dfs(int x)
{
	if(vs[x]) return fg[x];else vs[x]=1;
	for(int y:e1[x]) fg[x]|=dfs(y);
	return fg[x];
}
int main()
{
	read(n,m);for(int i=1,x,y;i<=m;i++) read(x,y),e1[x].push_back(y),ff[i]=x,tt[i]=y;
	vs[n]=fg[n]=1,dfs(1),memset(ds,0x3f,sizeof(ds)),ds[1]=0;
	for(int i=1;i<=n;i++) if(fg[i]) for(auto j:e1[i])
		if(fg[j]) fr[++et]=i,tw[et]=j,we[et]=2,fr[++et]=j,tw[et]=i,we[et]=-1;
	for(int i=1;i<=n;i++) for(int j=1;j<=et;j++) ds[tw[j]]=min(ds[fr[j]]+we[j],ds[tw[j]]);
	for(int i=1;i<=et;i++) if(ds[tw[i]]>ds[fr[i]]+we[i]) return puts("No"),0;
	puts("Yes");for(int i=1;i<=m;i++) if(fg[ff[i]]&&fg[tt[i]]) printf("%d\n",ds[tt[i]]-ds[ff[i]]);else puts("1");
	return 0;
}