#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int INF = 1e9;
const int MN = 6e5+5;
ll T,N,a,b,t,sz[MN],A,B;
vector<pii> G[MN];
string S;

void dfs(ll s, ll r)
{
    sz[s]=1;
    for(pii p : G[s]){
        if(p.va==r) continue;
        dfs(p.va,s);
        sz[s] += sz[p.va];
        if(sz[p.va]%2) A += p.vb;
        B += p.vb*min(sz[p.va],2*N-sz[p.va]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> T;
    while(T--){
        cin >> N;
        for(int i=1; i<2*N; i++){
            cin >> a >> b >> t;
            G[a].emplace_back(b,t);
            G[b].emplace_back(a,t);
        }
        dfs(1,1);
        cout << A << ' ' << B << '\n';
        A = B = 0;
        for(int i=1; i<=2*N; i++) G[i].clear();
    }
}