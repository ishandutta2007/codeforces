#include<cstdio>
#include<numeric>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=2005;
int n,k,MOD;
vector<int> G[N];
ll dp[N][N],s[N][N],res[N];
ll suf[N];
void dfs(int u,int fa) {
	fo(i,0,G[u].size()) if(G[u][i]==fa) {
		G[u].erase(G[u].begin()+i);
		break;
	}
	for(auto v:G[u]) dfs(v,u),res[v]=1;
	dp[u][0]=1;
	fo(i,1,n) {
		for(auto v:G[u]) (dp[u][i]+=dp[v][i]*res[v])%=MOD;
		suf[G[u].size()]=1;
		rf(j,int(G[u].size())-1,0)
			suf[j]=suf[j+1]*s[G[u][j]][i]%MOD;
		ll pre=1;
		fo(j,0,G[u].size()) {
			int v=G[u][j];
			(res[v]+=pre*suf[j+1])%=MOD;
			pre=pre*s[v][i]%MOD;
		}
		if(u^1) (dp[u][i]+=pre)%=MOD;
		else dp[u][i]=pre;
	}
	fo(i,0,n) s[u][i]=((i?s[u][i-1]:0)+dp[u][i])%MOD;
}
ll ans[N],tans[N],C[N][N];
int main() {
	cin>>n>>MOD;
	for(int i=1,u,v;i<n;++i) {
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	fr(i,0,n) {
		C[i][0]=1;
		fr(j,1,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
	}
	fo(k,0,n) fr(i,0,k) (ans[k]+=C[k][i]*dp[1][i+1]*(k-i&1?-1:1))%=MOD;
	rf(i,n-1,1) ans[i]=ans[i-1];
	ans[0]=1;
	fo(i,1,n) (ans[i]-=ans[i-1])%=MOD;
	tans[0]=1;
	fo(i,1,n) {
		tans[i]=(ans[i]-tans[i-1])%MOD;
		ans[i]=tans[i-1];
	}
	fo(i,1,n) printf("%lld ",(ans[i]+MOD)%MOD);
	puts("");
	return 0;
}

const int S=1<<21;
char p0[S],*p1,*p2;
#define getchar() (p2==p1&&(p2=(p1=p0)+fread(p0,1,S,stdin))==p1?EOF:*p1++)
inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}