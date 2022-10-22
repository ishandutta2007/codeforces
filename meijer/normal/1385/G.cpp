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

const int MX = 5e5;
int testCases;
int n, a[MX][2];
int cnt[MX];
int c[MX][2], r[MX][2];
vii adj[MX];
bool pos;
bitset<MX> visited;
int switched=0, tot=0;
int col[MX];
vi f, ans;

void dfs(int u, int color) {
    if(visited[u]) {
        if(col[u] != color) pos = 0;
        return;
    }
    visited[u] = 1;
    col[u] = color;
    tot++;
    if(color) switched++;
    f.pb(u);
    for(ii v:adj[u]) dfs(v.fi,color^v.se);
}

void program() {
    cin>>testCases;
    while(testCases--) {
        cin>>n;
        RE(j,2) RE(i,n) cin>>a[i][j];
        RE1(i,n) cnt[i]=0;

        pos = 1;
        RE(j,2) RE(i,n) {
            if(cnt[a[i][j]] == 2) {
                pos = 0;
                break;
            }
            c[a[i][j]][cnt[a[i][j]]] = i+1;
            r[a[i][j]][cnt[a[i][j]]] = j;
            cnt[a[i][j]]++;
        }

        if(!pos) {
            cout<<-1<<endl;
            continue;
        }

        RE1(i,n) adj[i].clear();
        RE1(i,n) {
            if(c[i][0] == c[i][1]) {
                continue;
            }
            RE(j,2) adj[c[i][j]].pb({c[i][!j], r[i][0] == r[i][1]});
        }

        RE1(i,n) visited[i] = 0;

        ans.clear();
        RE1(u,n) {
            tot = 0; switched = 0;
            if(!visited[u]) dfs(u,0);
            int bm = (switched > tot-switched);
            for(int v:f) if(col[v]^bm) ans.pb(v);
            f.clear();
        }

        if(!pos) {
            cout<<-1<<endl;
            continue;
        }

        cout<<ans.sz<<endl;
        RE(_pi,ans.sz) cout<<(_pi==0?"":" ")<<ans[_pi]; cout<<endl;
    }
}