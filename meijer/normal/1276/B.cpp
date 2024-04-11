#include <bits/stdc++.h>
using namespace std;

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

const int MX=2e5, MOD=1e9+7;

int t, n, m, a[2], sets[2];
vi adj[MX], adjA[MX];
int setA[2][MX];
bitset<MX> visited;

void dfs(bool s, int v) {
	if(visited[v]) return;
	visited[v] = 1;
	setA[s][v] = sets[s];
	for(int u:adj[v])
		dfs(s,u);
}
int getSize(int v) {
	if(visited[v]) return 0;
	visited[v] = 1;
	int ans = 1;
	for(int u:adjA[v])
		ans += getSize(u);
	return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--) {
    	cin>>n>>m>>a[0]>>a[1], a[0]--, a[1]--;
    	RE(i,n) adj[i].clear(), adjA[i].clear();
    	RE(i,m) {
    		int u, v;
    		cin>>u>>v; u--; v--;
    		adj[u].pb(v);
    		adj[v].pb(u);
    		if(u == a[0] || u == a[1] || v == a[0] || v == a[1]) continue;
    		adjA[u].pb(v);
    		adjA[v].pb(u);
    	}
    	RE(i,2) {
    		sets[i] = 0;
    		visited.reset();
    		visited[a[i]] = 1;
    		for(int v:adj[a[i]]) {
    			if(visited[v]) continue;
    			dfs(i,v);
    			sets[i]++;
    		}
    	}
    	visited.reset();
    	ll sizes[2];
    	sizes[0]=sizes[1]=0;
    	RE(v,n) {
    		if(v == a[0] || v == a[1]) continue;
    		if(visited[v]) continue;
    		if(setA[0][v] == setA[0][a[1]] && setA[1][v] == setA[1][a[0]])
    			getSize(v);
    		else {
    			if(setA[0][v] == setA[0][a[1]]) {
    				sizes[0] += getSize(v);
    			} else {
    				sizes[1] += getSize(v);
    			}
    		}
    	}
    	ll ans=sizes[0]*sizes[1];
    	cout<<ans<<endl;
    }
}