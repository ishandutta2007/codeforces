#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back

const int MX=5e5;
ll q;
ll n, k, U, V, W;
vii adjList[MX];
vii children[MX];
ll mem[MX][2];

void dfs(ll u, ll p) {
    for(ii v : adjList[u]) {
        if(v.first == p) continue;
        children[u].pb(v);
        dfs(v.first, u);
    }
}
ll getAns(ll u, bool c) {
    if(mem[u][c] == -1) {
        mem[u][c] = 0;
        vii bestOptions;
        for(ii v:children[u]) {
            ll connect   = getAns(v.first,1)+v.second;
            ll noConnect = getAns(v.first,0);
            bestOptions.pb({connect-noConnect,noConnect});
        }
        sort(bestOptions.begin(), bestOptions.end(), greater<ii>());
        int choosen = k-c;
        RE(i,bestOptions.size()) {
            if(i < choosen) mem[u][c] += max(bestOptions[i].second, bestOptions[i].second+bestOptions[i].first);
            else mem[u][c] += bestOptions[i].second;
        }
    }
    return mem[u][c];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>q;
    while(q--) {
        cin>>n>>k;
        RE(i,n) adjList[i].clear(), children[i].clear();
        RE(i,n-1) cin>>U>>V>>W,V--,U--, adjList[U].pb({V,W}), adjList[V].pb({U,W});
        dfs(0,-1);
        RE(i,n) mem[i][0]=mem[i][1]=-1;
        cout<<getAns(0,0)<<endl;
    }
}