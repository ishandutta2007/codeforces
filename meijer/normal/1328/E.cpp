#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second
#define sz size()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//===================//
//  Added libraries  //
//===================//

//===================//
//end added libraries//
//===================//

void program();
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	program();
}


//===================//
//   begin program   //
//===================//

const int MX = 5e5;
int n, m, f[MX];
vi adj[MX], chl[MX];
int p[MX];
int SEG[MX*4], LAZY[MX*4];
int bg[MX], ed[MX], cur=0;

void dfs(int u=1, int par=0) {
	p[u] = par;
	for(int v:adj[u]) if(v!=par) dfs(v,u), chl[u].pb(v);
}
void dfs2(int u=1) {
	bg[u] = cur++;
	for(int v:chl[u]) dfs2(v);
	ed[u] = cur-1;
}
void addSeg(int i, int j, int x, int lazy=0, int p=0, int l=0, int r=n-1) {
	SEG [p] += lazy;
	LAZY[p] += lazy;
	if(j < l || i > r) return;
	if(i <= l && j >= r) {
		SEG [p] += x;
		LAZY[p] += x;
		return;
	}
	int m=(l+r)/2;
	addSeg(i,j,x,LAZY[p],p*2+1,l,m);
	addSeg(i,j,x,LAZY[p],p*2+2,m+1,r);
	LAZY[p] = 0;
	SEG[p] = max(SEG[p*2+1], SEG[p*2+2]);
}

void program() {
	cin>>n>>m;
	RE(i,n-1) {
		int u, v; cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs();
	dfs2();
	RE(i,n*4) SEG[i]=LAZY[i]=0;
	RE(i,m) {
		int k;
		cin>>k;
		RE(i,k) cin>>f[i];
		RE(i,k) if(f[i] != 1) f[i] = p[f[i]];
		RE(i,k) addSeg(bg[f[i]], ed[f[i]],  1);
		bool ans = (SEG[0] == k);
		cout<<(ans?"YES":"NO")<<endl;
		RE(i,k) addSeg(bg[f[i]], ed[f[i]], -1);
	}
}