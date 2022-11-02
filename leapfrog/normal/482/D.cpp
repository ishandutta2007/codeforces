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
const int N=100005,P=1e9+7;vector<int>v[N];
struct edge{int to,nxt;}e[N<<1];int n,et,head[N],F[N][2],G[N][2];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x)
{
	F[x][1]=1,F[x][0]=0;for(auto y:v[x])
	{
		dfs(y);int f0=F[x][0],f1=F[x][1];
		F[x][0]=(F[x][0]+1ll*f0*F[y][0]+1ll*f1*F[y][1])%P;
		F[x][1]=(F[x][1]+1ll*f1*F[y][0]+1ll*f0*F[y][1])%P;
	}F[x][0]=(F[x][0]<<1)%P,F[x][1]=(F[x][1]<<1)%P;
	reverse(v[x].begin(),v[x].end());
	int cn=1,g[2]={0,1},tmp;for(auto y:v[x]) cn=1ll*cn*(F[y][0]+1)%P;
	for(auto y:v[x]) tmp=g[0],g[0]=(g[0]+1ll*g[1]*F[y][1])%P,g[1]=(g[1]+1ll*tmp*F[y][1])%P;
	F[x][0]=(F[x][0]+P-g[0])%P,F[x][1]=(F[x][1]+P-cn)%P;
}
int main()
{
	read(n);for(int i=2,f;i<=n;i++) read(f),v[f].push_back(i);
	return dfs(1),printf("%d\n",(F[1][0]+F[1][1])%P),0;
}