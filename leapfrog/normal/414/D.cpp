//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
struct edge{int to,nxt;}e[200005];int et,head[100005],n,K,P,tn[100005],d[100005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs0(int x,int fa) {d[x]=d[fa]+1;for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs0(e[i].to,x);}
int main()
{
	read(n),read(K),read(P),K=min(K,n);for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	dfs0(1,0),sort(d+1,d+n+1);int l=2,r=2,nwp=0,res=1;for(;l<n&&r<n;res=max(res,r-l+1))
	{
		r++;if(d[r]^d[r-1]) nwp+=r-l;
		while(nwp>P||r-l+1>K) nwp-=d[r]-d[l],l++;
	}
	return printf("%d\n",res),0;
}