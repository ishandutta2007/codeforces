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
const int P=1e9+7;int n,B[100005],K[100005];
struct edge{int to,w,nxt;}e[200005];int et,head[100005];
inline void chk(int &x) {x>=P?x-=P:x;}
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline void dfs(int x,int fa)
{
	int q=0,cnt=0;for(int i=head[x];i;cnt++,B[x]=(B[x]+e[i].w),i=e[i].nxt)
		if(e[i].to^fa) dfs(e[i].to,x),B[x]=(B[e[i].to]+1ll*B[x])%P,chk(q+=K[e[i].to]);
	if(cnt==1) return K[x]=B[x]=0,void();else K[x]=1;
//	printf("%d : %d %d\n",x,K[x],B[x]);
	chk(q=cnt-q+P),q=ksm(q),K[x]=1ll*K[x]*q%P,B[x]=1ll*B[x]*q%P;
}
int main()
{
	read(n);for(int i=1,x,y,w;i<n;i++) read(x),read(y),++x,++y,read(w),adde(x,y,w),adde(y,x,w);
	return dfs(1,0),printf("%d\n",B[1]),0;//for(int i=1;i<=n;i++) printf("%d %d\n",K[i],B[i]);
}