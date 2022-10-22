#include <bits/stdc++.h>
using namespace std;

// macros
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> lll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<lll> vlll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define FOR(a,b) for(auto& a : b)
#define all(a) a.begin(), a.end()
#define INF 1e9
#define EPS 1e-9
#define pb push_back
#define popb pop_back
#define fi first
#define se second
#define sz size()

// input
template<class T> void IN(T& x) {cin >> x;}
template<class H, class... T> void IN(H& h, T&... t) {IN(h); IN(t...); }

// output
template<class T1, class T2> void OUT(const pair<T1,T2>& x);
template<class T> void OUT(const T& x) {cout << x;}
template<class H, class... T> void OUT(const H& h, const T&... t) {OUT(h); OUT(t...); }
template<class T1, class T2> void OUT(const pair<T1,T2>& x) {OUT(x.fi," ",x.se);}
template<class... T> void OUTL(const T&... t) {OUT(t..., "\n"); }

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

const int MX = 14e5;

int dx8[]={ 0, 1, 1, 1, 0,-1,-1,-1};
int dy8[]={ 1, 1, 0,-1,-1,-1, 0, 1};

int n, t, m=0;
int R[MX], C[MX];
int OR[MX], OC[MX];
int adj[MX][8];
int F[MX];
bitset<MX> visited, build, out, hasEmptyConnected;
map<ii,int> f;
map<ii,int> posID;
set<int> pq;
vi ans;
int outside;
set<int> updateDestroy;

int p[MX], r[MX];
void buildDSU(int dsuSize) {
    RE(i,dsuSize) p[i]=i, r[i]=0;
}
int getSet(int i) {return i==p[i]?i:p[i]=getSet(p[i]);}
bool isSameSet(int i, int j) {return getSet(i)==getSet(j);}
void unionSet(int i, int j) {
    if(!isSameSet(i,j)) {
        i=p[i], j=p[j];
        if(r[i] > r[j]) {
            p[j] = i;
        } else {
            p[i] = j;
            if(r[i] == r[j]) r[j]++;
        }
    }
}

bool canDestroy(int p) {
    if(!hasEmptyConnected[p]) return 0;

    int start=0;
    bitset<8> isBuild;
    RE(d,8) {
        isBuild[d] = build[adj[p][d]];
        if(isBuild[d])
            start = d;
    }
    RE(d,4) {
        int cd=d*2;
        int nd=(cd+2)%8;
        if(isBuild[cd] && isBuild[nd])
            isBuild[(cd+1)%8]=1;
    }

    set<int> curRegions;
    bool last=1;
    int pos=(start+1)%8;
    while(pos != start) {
        if(last && !isBuild[pos]) {
            int reg = getSet(adj[p][pos]);
            if(curRegions.count(reg)) return 0;
            curRegions.insert(reg);
        }
        last = isBuild[pos];
        pos=(pos+1)%8;
    }

    return 1;
}
void updateBuild(int p) {
    if(p == -1) return;
    if(canDestroy(p)) {
        pq.insert(F[p]);
    } else {
        pq.erase(F[p]);
    }
}
void addOutside(int p) {
    if(p == -1) return;
    if(out[p]) return;

    bitset<8> isBuild; isBuild.reset();
    RE(d,8)
        if(adj[p][d] != -1)
            isBuild[d] = build[adj[p][d]];
    if(!isBuild.count()) return;

    out[p] = 1;
    RE(d,4) {
        if(!isBuild[d*2])
            addOutside(adj[p][d*2]);
        else
            hasEmptyConnected[adj[p][d*2]] = 1;
    }
    RE(d,8)
        if(isBuild[d])
            updateDestroy.insert(adj[p][d]);
}

void dfsPossible(int u) {
    if(u == -1) return;
    if(!build[u]) return;
    if(visited[F[u]]) return;
    visited[F[u]] = 1;
    RE(d,8)
        dfsPossible(adj[u][d]);
}
bool isPossible() {
    visited.reset();
    dfsPossible(0);
    RE1(i,n) if(!visited[i]) return 0;
    return 1;
}

void addPossible(ii p) {
    if(posID.count(p)) return;
    posID[p] = m++;
}

void program() {
    IN(n,t);
    RE1(i,n) IN(R[i],C[i]);
    RE1(i,n) OR[i]=R[i], OC[i]=C[i];
    RE1(i,n) f[{R[i],C[i]}] = i;

    build.reset();
    out.reset();
    hasEmptyConnected.reset();

    // cordinate compression
    RE1(i,n) {
        int x=R[i], y=C[i];
        addPossible({x,y});
        RE(d,8) {
            int nx=x+dx8[d];
            int ny=y+dy8[d];
            addPossible({nx,ny});
        }
    }
    FOR(p,posID) {
        int x = p.fi.fi;
        int y = p.fi.se;
        RE(d,8) {
            int nx=x+dx8[d];
            int ny=y+dy8[d];
            if(posID.count({nx,ny})) adj[p.se][d] = posID[{nx,ny}];
            else adj[p.se][d] = -1;
        }
        R[p.se] = x;
        C[p.se] = y;
        if(f.count({x,y})) F[p.se] = f[{x,y}], build[p.se] = 1;
    }

    if(!isPossible()) {
        OUTL("NO");
        return;
    }

    // create dsu
    buildDSU(m);
    FOR(p,posID) {
        int u=p.se;
        if(build[u]) continue;
        RE(d,4) {
            int v=adj[u][d*2];
            if(v == -1) continue;
            if(build[v]) continue;
            unionSet(u, v);
        }
    }

    // set outside
    ii start = {OR[1],OC[1]};
    RE1(i,n) start = min(start, {OR[i],OC[i]});
    start.fi--;
    outside = posID[start];
    addOutside(outside);
    FOR(p,updateDestroy) updateBuild(p);
    updateDestroy.clear();

    // find solution
    while(!pq.empty()) {
        int p = *(--pq.end()); pq.erase(p);
        int x = OR[p];
        int y = OC[p];
        int u = posID[{x,y}];
        build[u] = 0;

        // update dsu
        RE(d,4) {
            int v = adj[u][d*2];
            if(v == -1) continue;
            if(build[v]) continue;
            unionSet(u, v);
        }

        addOutside(u);
        FOR(p,updateDestroy) updateBuild(p);
        updateDestroy.clear();

        ans.pb(p);
    }

    OUTL("YES");
    reverse(all(ans));
    FOR(i,ans) OUTL(i);
}