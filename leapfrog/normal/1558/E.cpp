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
int n,m,a[1005],b[1005],ls[1005];ll ds[1005];char fg[1005],v[1005];
struct edge{int to,nxt;}e[4005];int et,head[1005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline char chk(ll w)
{
	fg[1]=1;for(int i=2;i<=n;i++) fg[i]=0;
	while(1145141919810)
	{
		for(int i=1;i<=n;i++) v[i]=fg[i],ls[i]=0,ds[i]=0;
		queue<int>q;for(int i=1;i<=n;i++) if(fg[i]) q.push(i),ds[i]=w;
		int X=0,Y=0;while(!q.empty())
		{
			int x=q.front();q.pop();
			for(int i=head[x];i;i=e[i].nxt)
			{
				int y=e[i].to;if(fg[x]&&fg[y]) continue;
				if(ds[x]<=a[y]||y==ls[x]) continue;
				if(v[y]) {X=x,Y=y;break;}
				v[y]=1,ls[y]=x,ds[y]=ds[x]+b[y],q.push(y);
			}if(X) break;if(X) break;if(X) break;if(X) break;
		}
		if(!X) return 0;
		for(;!fg[X];X=ls[X]) fg[X]=1,w+=b[X];
		for(;!fg[Y];Y=ls[Y]) fg[Y]=1,w+=b[Y];
		char qwq=1;for(int i=1;i<=n;i++) qwq&=fg[i];
		if(qwq) return 1;
	}return '@';
}
inline void solve()
{
	read(n,m),et=0,memset(head,0,sizeof(head));int l=1,r=1e9+1,rs=r;
	for(int i=2;i<=n;i++) read(a[i]);
	for(int i=2;i<=n;i++) read(b[i]);
	for(int i=1,x,y;i<=m;i++) read(x,y),adde(x,y),adde(y,x);
	while(l<=r) {int md=(l+r)>>1;if(chk(md)) rs=md,r=md-1;else l=md+1;}
	printf("%d\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}