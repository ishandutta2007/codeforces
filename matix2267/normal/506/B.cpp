#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
//#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

#if 1
	#define DEB printf
#else
	#define DEB(...)
#endif

typedef long long ll;
typedef long long LL;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int inft = 1000000009;
const int mod = 1000000007;
const int MAXN = 1000006;

vector<vi> V,W;
vi vis;

void dfs(int u, int c) {
	if(vis[u] != -1) return;
	vis[u]=c;
	tr(it, W[u]) dfs(*it, c);
}

void solve() {
	int n,m;
	scanf("%d%d",&n,&m);
	V.resize(n); W.resize(n);
	vi st(n); vis.resize(n,-1);
	fru(j,m) {
		int a,b;
		scanf("%d%d",&a,&b);
		a--; b--;
		V[a].pb(b);
		W[a].pb(b);
		W[b].pb(a);
		st[b]++;
	}
	int nc = 0;
	fru(i,n) if(vis[i]==-1) dfs(i,nc++);
	queue<int> Q;
	fru(i,n) if(st[i] == 0) Q.push(i);
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		tr(it,V[u]) if(--st[*it] == 0) Q.push(*it);
	}
	vi AAA;
	fru(i,n) if(st[i] != 0) AAA.pb(vis[i]);
	sort(ALL(AAA));
	AAA.resize(unique(ALL(AAA)) - AAA.begin());
	int nv = AAA.size();
	printf("%d\n", n-nc+nv);
//	DEB("%d %d %d\n",n,nc,nv);
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) solve();
	return 0;
}