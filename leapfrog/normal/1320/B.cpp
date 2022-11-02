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
struct edge{int to,nxt;}e[200005];int et,head[200005];
int n,m,K,ds[200005],a[200005];vector<int>E[200005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline char chk(int x,int y) {for(auto z:E[x]) if(z^y&&ds[z]==ds[x]-1) return 1;return 0;}
int main()
{
	read(n,m);for(int i=1,x,y;i<=m;i++) read(x,y),adde(y,x),E[x].push_back(y);
	read(K);queue<int>q;for(int i=1;i<=K;i++) read(a[i]);
	q.push(a[K]),memset(ds,0x3f,sizeof(ds)),ds[a[K]]=0;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=head[x];i;i=e[i].nxt) if(ds[e[i].to]>ds[x]+1)
			ds[e[i].to]=ds[x]+1,q.push(e[i].to);
	}
	int c1=0;for(int i=1;i<K;i++) c1+=ds[a[i]]-1!=ds[a[i+1]];
	int c2=0;for(int i=1;i<K;i++) c2+=chk(a[i],a[i+1]);
	return printf("%d %d\n",c1,c2),0;
}