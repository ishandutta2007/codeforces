#include<cstdio>
#include<queue>
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

const int N=1005,MOD=998244353;
int t,n,m,a[N];
vector<int> G[N];
bool dp[N][N]; int f[N];
int du[N];
int main() {
	cin>>t;
	while(t--) {
		cin>>n>>m;
		fr(i,1,n) cin>>a[i],G[i].clear();
		for(int i=1,u,v;i<=m;++i) {
			cin>>u>>v;
			G[u].push_back(v);
			++du[v];
		}
		fr(i,1,n) {
			fr(j,0,m) dp[i][j]=0;
			f[i]=0;
		}
		queue<int> q;
		fr(i,1,n) if(!du[i]) q.push(i);
		int u; while(!q.empty()) {
			u=q.front(); q.pop();
			int res=a[u];
			fr(i,0,m) if(!dp[u][i]&&res) dp[u][i]=1,--res;
			(f[u]+=res)%=MOD;
			for(auto v:G[u]) {
				if(!--du[v]) q.push(v);
				res=0;
				fr(i,0,m) {
					if(i) res+=dp[u][i-1];
					if(!dp[v][i]&&res) dp[v][i]=1,--res;
				}
				(res+=dp[u][m]+f[u])%=MOD;
				(f[v]+=res)%=MOD;
			}
		}
		if(f[u]) printf("%d\n",(f[u]+m+1)%MOD);
		else {
			rf(i,m,-1) if(i==-1||dp[u][i]) {
				printf("%d\n",(i+1)%MOD);
				break;
			}
		}
	}
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