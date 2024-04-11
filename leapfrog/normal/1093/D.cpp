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
const int P=998244353;int cl[300005];struct node{int ev,od;char cg;};
int T,n,m,et,head[300005];struct edge{int to,nxt;}e[600005];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline node dfs(int x)
{
	node r=(node){!cl[x],cl[x],1};for(int i=head[x];i;i=e[i].nxt)
		if(~cl[e[i].to]) {if(cl[x]==cl[e[i].to]) return(node){0,0,0};}
		else {cl[e[i].to]=cl[x]^1;node x=dfs(e[i].to);if(!x.cg) return x;else r.ev+=x.ev,r.od+=x.od;}
	return r;
}
inline int ksm(int x,int q) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void solve()
{
	et=0,read(n),read(m),memset(cl+1,-1,n<<2),memset(head+1,0,n<<2);
	for(int i=1,x,y;i<=m;i++) read(x),read(y),adde(x,y),adde(y,x);
	int res=1;for(int i=1;i<=n;i++) if(cl[i]==-1)
	{
		cl[i]=0;node x=dfs(i);//printf("%d , %d ( %d\n",x.ev,x.od,x.cg);
		if(!x.cg) return puts("0"),void();else res=1ll*res*(ksm(2,x.ev)+ksm(2,x.od))%P;
	}
	printf("%d\n",res);
}
int main() {for(read(T);T--;) solve();return 0;}