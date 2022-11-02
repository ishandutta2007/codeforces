#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

vector<pair<int, pair<ll, int> > > g[303030];
vector<int> gg[303030];
int used[303030];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b, {c, i+1}});
        g[b].push_back({a, {c, i+1}});
    }
    int u;
    cin>>u;
    priority_queue<pair<pair<ll, ll>, pair<int, int> > > dij;
    dij.push({{0, 0}, {u, 0}});
    ll v=0;
    vector<int> vv;
    while (!dij.empty()){
        auto x=dij.top();
        dij.pop();
        if (used[x.S.F]) continue;
        used[x.S.F]=1;
        if (x.S.S>0) vv.push_back(x.S.S);
        v+=-x.F.S;
        for (auto nx:g[x.S.F]){
            dij.push({{x.F.F-nx.S.F, -nx.S.F}, {nx.F, nx.S.S}});
        }
    }
    cout<<v<<endl;
    for (int vvv:vv){
        cout<<vvv<<" ";
    }
}