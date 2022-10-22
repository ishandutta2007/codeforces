#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(ll a=ll(b); a<ll(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(ll a=ll(c-1); a>=ll(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second
#define sz size()

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

const ll MX = 5e5;
ll t, n, m, a, b, c;
ll p[MX];
vi adj[MX];
ll df[MX][3];
ll smP[MX];

ll fillDist(int orig, int c) {
    RE1(i,n) df[i][c] = -1;
    queue<int> q;
    df[orig][c] = 0; q.push(orig);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v:adj[u]) {
            if(df[v][c] == -1) {
                df[v][c] = df[u][c] + 1;
                q.push(v);
            }
        }
    }
}

void program() {
    cin>>t;
    while(t--) {
        cin>>n>>m>>a>>b>>c;
        RE1(i,n) adj[i].clear();
        RE(i,m) cin>>p[i];
        RE(i,m) {
            ll u, v; cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        sort(p, p+m);
        fillDist(a, 0);
        fillDist(b, 1);
        fillDist(c, 2);
        smP[0] = 0;
        RE(i,m) smP[i+1] = smP[i]+p[i];
        ll ans=1e18;
        RE1(i,n) if(df[i][0]+df[i][1]+df[i][2] <= m) {
            ans = min(ans, smP[df[i][1]] + smP[df[i][0]+df[i][1]+df[i][2]]);
        }
        cout<<ans<<endl;
    }
}