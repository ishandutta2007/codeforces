//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int Ca,n,et,head[100005],nx[100005],deg[100005];struct edge{int to,nxt;}e[200005];
char v[100005];struct node{int a,b,tp;}a[200005];int at,fa[100005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et,deg[x]++;}
inline int get(int x) {if(nx[x]) return get(nx[x]);else return x;}
inline void dfs(int x,int fa)
{
	int a=-1,b=-1;::fa[x]=fa;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa)
	{
		dfs(e[i].to,x);if(v[e[i].to]) continue;
		if(a==-1) a=e[i].to;else if(b==-1) b=e[i].to;else ::a[++at]=(node){e[i].to,get(e[i].to),e[i].to};
	}
	if(~b) ::a[++at]=(node){get(a),get(b),x},v[x]=1;
	else if(~a) nx[x]=a;else nx[x]=0;
}
inline void solve()
{
	read(n),et=at=0;for(int i=1;i<=n;i++) head[i]=v[i]=nx[i]=deg[i]=0;
	for(int i=1,x,y;i<n;i++) read(x),read(y),adde(x,y),adde(y,x);
	int rt=1;for(int i=1;i<=n;i++) if(deg[i]>=2) rt=i;
	dfs(rt,0);if(a[at].tp!=rt) a[++at]=(node){rt,get(rt),rt};
//	for(int i=1;i<=at;i++) printf("%d %d %d\n",a[i].a,a[i].b,a[i].tp);
	printf("%d\n",at-1);int ls=a[at].b;
	for(int i=at-1;i;i--) printf("%d %d %d %d\n",a[i].tp,fa[a[i].tp],ls,a[i].b),ls=a[i].a;
}
int main() {for(read(Ca);Ca--;) solve();return 0;}