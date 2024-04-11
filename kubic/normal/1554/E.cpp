#include <bits/stdc++.h>
using namespace std;
#define N 300005
#define LIM 1000005
#define MOD 998244353
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
#define pb push_back
char buf[LIM],*P1,*P2;
int T,n,w[N],f[N];vector<int> e[N];
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+c-48,c=gc();return res;
}
int qPow(int x,int y)
{int res=1;for(;y;y/=2,x=1ll*x*x%MOD) if(y&1) res=1ll*res*x%MOD;return res;}
bool dfs(int u,int f,int x)
{
	int s=0;for(auto v:e[u]) if(v!=f) {if(!dfs(v,u,x)) return 0;s+=w[v]^1;}
	s%=x;if(!s) {w[u]=0;return 1;}if(s==x-1) {w[u]=1;return 1;}return 0;
}
void slv()
{
	n=rd();for(int i=1;i<=n;++i) e[i].clear();
	for(int i=1,u,v;i<n;++i) u=rd(),v=rd(),e[u].pb(v),e[v].pb(u);
	for(int i=1;i<=n;++i) f[i]=0;f[1]=qPow(2,n-1);
	for(int i=2;i<n;++i) if(!((n-1)%i)) f[i]=dfs(1,0,i) && !w[1];
	for(int i=n;i;--i) for(int j=i*2;j<=n;j+=i) f[i]-=f[j];
	for(int i=1;i<=n;++i) printf("%d ",(f[i]+MOD)%MOD);puts("");
}
int main() {T=rd();while(T--) slv();return 0;}