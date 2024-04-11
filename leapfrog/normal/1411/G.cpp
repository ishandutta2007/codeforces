//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
struct edge{int to,nxt;}e[200005];int n,m,et,head[100005],dg[100005];
const int P=998244353,L=512;int sg[100005],cn[515];char fg[325];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et,dg[y]++;}
struct node
{
	int n,a[515][515];
	inline int* operator[](int i) {return a[i];}
	inline void swap(int x,int y) {if(x!=y) for(int i=0;i<=n;i++) swap(a[x][i],a[y][i]);}
	inline void times(int x,int k) {for(int i=0;i<=n;i++) a[x][i]=1ll*a[x][i]*k%P;}
	inline void add(int x,int y,int k) {for(int i=0;i<=n;i++) a[x][i]=(1ll*a[y][i]*k+a[x][i])%P;}
}F;
inline void dfs(int x)
{
	if(~sg[x]) return;else for(int i=head[x];i;i=e[i].nxt) dfs(e[i].to);
	memset(fg,0,sizeof(fg));for(int i=head[x];i;i=e[i].nxt) fg[sg[e[i].to]]=1;
	for(sg[x]=0;;sg[x]++) if(!fg[sg[x]]) return cn[sg[x]]++,void();
}
inline void guass(node &a)
{
	for(int i=0;i<a.n;i++)
	{
		for(int j=i;j<a.n;j++) if(a[j][i]) {a.swap(i,j);break;}
		a.times(i,ksm(a[i][i]));for(int j=i+1;j<a.n;j++) a.add(j,i,P-a[j][i]);
	}
	for(int i=a.n-1;~i;i--) for(int j=0;j<i;j++) a.add(j,i,P-a[j][i]);
}
int main()
{
	read(n),read(m);for(int i=1,x,y;i<=m;i++) read(x),read(y),adde(x,y);
	memset(sg,-1,sizeof(sg));for(int i=1;i<=n;i++) if(!dg[i]) dfs(i);
	int iv=ksm(n+1);F.n=L;for(int i=1;i<L;i++)
		{F[i][i]=P-1;for(int j=0;j<L;j++) F[i][j]=(F[i][j]+1ll*cn[i^j]*iv)%P;}
	for(int i=0;i<=L;i++) F[0][i]=1;
	//for(int i=0;i<4;i++) for(int j=0;j<=4;j++) printf("%d%c",F[i][j],j==F.n?'\n':' ');
	return guass(F),printf("%d\n",(P+1-F[0][L])%P),0;
}