#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=501000;
VI e[N],c[N];
int pos[N],neg[N],chs[N],q[N],t,n,m,k,v,f[N],ef[N],dd[N],vis[N];
vector<PII> ee[N];
int find(int x) { return f[x]==x?x:f[x]=find(f[x]); }
void del(int x) {
//	printf("DEL %d\n",x);
	for (auto vv:e[x]) {
		int v=abs(vv);
		if (dd[v]) continue;
		dd[v]=1;
		for (auto ww:c[v]) {
			int w=abs(ww);
			if (ww>0) pos[w]--;
			else neg[w]--;
			if ((pos[w]==0||neg[w]==0)&&!vis[w]) {
				q[t++]=w; vis[w]=1; chs[w]=(neg[w]==0);
			}
		}
	}
}
void dfs(int u,int f,int eg) {
	if (eg<0) chs[-eg]=1; else chs[eg]=0;
	for (auto p:ee[u]) {
		if (p.fi==f) continue;
		dfs(p.fi,u,p.se);
	}
}
int main() {
//	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) {
		scanf("%d",&k);
		rep(j,0,k) {
			scanf("%d",&v);
			c[i].pb(v);
			if (v>0) e[v].pb(i),pos[v]++;
			else e[-v].pb(-i),neg[-v]++;
		}
	}
	rep(i,1,m+1) if (pos[i]==0||neg[i]==0) q[t++]=i,vis[i]=1,chs[i]=(neg[i]==0);
	rep(i,0,t) del(q[i]);
	rep(i,1,n+1) f[i]=i,ef[i]=-1;
	rep(i,1,m+1) if (!vis[i]) {
		assert(pos[i]==1&&neg[i]==1&&SZ(e[i])==2);
		int u=e[i][0],v=e[i][1];
		assert(!dd[abs(v)]&&!dd[abs(u)]);
		if (v>0&&u<0) swap(u,v); assert(v<0&&u>0);
		v*=-1;
		if (find(u)!=find(v)) {
			ee[u].pb(mp(v,i)),ee[v].pb(mp(u,-i));
			if (ef[find(u)]==-1&&ef[find(v)]!=-1) ef[find(u)]=ef[find(v)];
			f[find(v)]=find(u);
		} else {
			if (ef[find(u)]==-1) ef[find(u)]=i;
		}
	}
	rep(i,1,n+1) {
		if (dd[i]||find(i)!=i) continue;
		if (ef[i]==-1) {
			puts("NO");
			return 0;
		}
		int u=e[ef[i]][0],v=e[ef[i]][1];
		assert(!dd[abs(v)]&&!dd[abs(u)]);
		if (v>0&&u<0) swap(u,v); assert(v<0&&u>0);
		v*=-1;
		dfs(u,0,-ef[i]);
	}
	puts("YES");
	rep(i,1,m+1) putchar('0'+chs[i]); puts("");
}