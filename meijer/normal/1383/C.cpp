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

const int MX = 20, BIT=(1<<MX);
int testCases;
int n;
string a, b;
vi adj[MX];
int dp[BIT];
bitset<MX> visited;
int comp;
int reach[MX];

void dfs(int u) {
    if(visited[u]) return;
    visited[u] = 1;
    for(int v:adj[u]) dfs(v);
}

void program() {
    cin>>testCases;
    while(testCases--) {
        cin>>n>>a>>b;
        RE(i,n) a[i] -= 'a';
        RE(i,n) b[i] -= 'a';

        RE(i,MX) reach[i] = 0;
        RE(i,MX) adj[i].clear();
        RE(i,n) if(a[i] != b[i]) {
            reach[a[i]] |= (1<<b[i]);
            adj[a[i]].pb(b[i]);
            adj[b[i]].pb(a[i]);
        };

        comp = 0;
        visited.reset();
        RE(i,MX) if(!visited[i]) dfs(i), comp++;


        int mx=0;
        RE(i,BIT) {
            dp[i] = (i == 0 ? 1 : 0);
            RE(j,MX) if(i & (1<<j)) {
                dp[i] |= (dp[i ^ (1<<j)] && ((i & reach[j]) == 0));
            }
            if(dp[i]) mx = max(mx, __builtin_popcount(i));
        }

        int ans = 2*MX - comp - mx;
        cout<<ans<<endl;
    }
}