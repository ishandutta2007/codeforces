#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=2e5, MOD=1e9+7;;
int n, m, a, b;
vi adjList[MX];
set<int> comp;
int p[MX], r[MX], sz[MX];
int compCnt[MX];

void buildDSU() {
	RE(i,n) p[i]=i, r[i]=0, sz[i]=1;
}
int getSet(int i) {return p[i]==i ? i : p[i]=getSet(p[i]);}
bool isSameSet(int i, int j) {return getSet(i) == getSet(j);}
void unionSet(int i, int j) {
	if(!isSameSet(i, j)) {
		i=getSet(i), j=getSet(j);
		if(r[i] > r[j]) {
			p[j] = i;
			sz[i] += sz[j];
			comp.erase(j);
		} else {
			p[i] = j;
			sz[j] += sz[i];
			comp.erase(i);
			if(r[i] == r[j]) r[j]++;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    RE(i,m) cin>>a>>b, a--, b--, adjList[a].pb(b), adjList[b].pb(a);
    RE(i,n) sort(adjList[i].begin(), adjList[i].end());
    
    buildDSU();
    RE(i,n) {
    	for(int v:comp) compCnt[v] = 0;
    	RE(j,adjList[i].size()) {
    		if(adjList[i][j] > i) break;
    		compCnt[getSet(adjList[i][j])]++;
    	}
    	comp.insert(i);
    	set<int> compc = comp;
    	for(int v:compc) {
    		if(v == i) continue;
    		if(compCnt[v] != sz[v]) {
    			unionSet(v, i);
    		}
    	}
    }

    cout<<(comp.size()-1)<<endl;
}