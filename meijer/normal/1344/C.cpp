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
int n, m, J[MX], K[MX];
vi chl[MX];
vi par[MX];
bitset<MX> visited;
bitset<MX> visited2;
bitset<MX> inLoop;
char ans[MX];
bool possible = 1;

void visit(int u) {
    if(inLoop[u]) possible = 0;
    if(visited[u]) return;
    inLoop[u] = 1;
    visited[u] = 1;
    for(int v:par[u]) visit(v);
    inLoop[u] = 0;
}
void visit2(int u) {
    if(inLoop[u]) possible = 0;
    if(visited2[u]) return;
    inLoop[u] = 1;
    visited2[u] = 1;
    for(int v:chl[u]) visit2(v);
    inLoop[u] = 0;
}

void program() {
    cin>>n>>m;
    RE(i,m) cin>>J[i]>>K[i];
    RE(i,m) {
        chl[K[i]].pb(J[i]);
        par[J[i]].pb(K[i]);
    }
    visited.reset(); visited2.reset(); inLoop.reset();
    int cnt=0;
    RE1(i,n) {
        if(visited[i]||visited2[i]) ans[i] = 'E';
        else           ans[i] = 'A', cnt++;
        visit(i);
        visit2(i);
    }
    if(!possible) {
        cout<<-1<<endl;
        return;
    }
    cout<<cnt<<endl;
    RE1(i,n) cout<<ans[i];
    cout<<endl;
}