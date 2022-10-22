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

const ll MX=2e5, MOD=1e9 + 7;
ll n, a, b;
ll x[MX];
vi adjList[MX];
map<ll, ll> ans[MX];

ll gcd(ll a, ll b) {return b==0?a:gcd(b,a%b);}
ll dfs(ll u=0, ll p=-1) {
    ll cans=0;
    ans[u][x[u]]++;
    if(p != -1) {
        for(auto it:ans[p]) {
            ans[u][gcd(x[u], it.first)] += it.second;
        }
    }
    for(auto it:ans[u])
        cans += (it.first * it.second)%MOD, cans %= MOD;
    for(ll v:adjList[u]) {
        if(v==p) continue;
        cans += dfs(v, u);
        cans %= MOD;
    }
    return cans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    RE(i,n) cin>>x[i];
    RE(i,n-1) cin>>a>>b, a--, b--, adjList[a].pb(b), adjList[b].pb(a);
    cout<<dfs()<<endl;
}