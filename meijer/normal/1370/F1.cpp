#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
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

const int MX = 2000;
int n, t;
vi adj[MX], chl[MX];
int p[MX];
int dist;
int cent;
set<int> s;
map<int, ii> mem;

ii ask() {
    cout<<"? "<<s.sz;
    for(int i:s) cout<<" "<<i;
    cout<<endl;
    cout.flush();
    int x, d;
    cin>>x>>d;
    return {x, d};
}
void dfsChl(int u, int parent) {
    p[u] = parent;
    for(int v:adj[u]) if(v != parent) dfsChl(v, u), chl[u].pb(v);
}
void dfsDist(int u, int parent, int depth) {
    if(depth == 0) s.insert(u);
    for(int v:adj[u]) if(v != parent) dfsDist(v, u, depth-1);
}
ii ask(int border) {
    if(mem.find(border) != mem.end())
        return mem[border];

    s.clear();
    dfsDist(cent,0,border);
    if(s.sz == 0) return mem[border] = {0,0};
    return mem[border] = ask();
}

void program() {
    cin>>t;
    while(t--) {
        cin>>n;
        RE(i,n+1) adj[i].clear();
        RE(i,n+1) chl[i].clear();
        RE(i,n-1) {
            int u, v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfsChl(1, -1);

        s.clear();
        RE1(i,n) s.insert(i);
        ii pf = ask();
        cent = pf.fi;
        dist = pf.se;
        s.clear();

        mem.clear();
        int lb=0, ub=dist;
        while(lb != ub) {
            int mid=(lb+ub+1)/2;
            if(ask(mid).se == dist) lb=mid;
            else ub=mid-1;
        }
        ii p1 = ask(lb);

        s.clear();
        dfsDist(p1.fi, 0, p1.se);
        ii p2 = ask();
        cout<<"! "<<p1.fi<<" "<<p2.fi<<endl;
        cout.flush();
        string ret;
        cin>>ret;
    }
}