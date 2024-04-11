#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
/**
    haven't rewrite yet. :P whatever, too lazy to write it myself.
*/

bool vis[nax];
int d[nax];
vector <int> topo;
vector <int> a[nax];
bool ok;
void topsort(int nod){
    vis[nod]=true;
    d[nod]=true;
    for(int i:a[nod]){
        if(!vis[i]){
            topsort(i);
        }
        else if(d[i]){
            ok=false;
        }
    }
    d[nod]=false;
    topo.push_back(nod);
}

int where[nax];

int n, m;

void solve () {
    cin >> n >> m;
    vector < pair <int, int>> un, di;
    for (int i = 1 ; i <= m ; ++ i) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            un.emplace_back(u, v);
        } else a[u].push_back(v), di.emplace_back(u, v);
    }
    ok = true;

    for (int i = 1 ; i <= n ; ++ i) {
        if (!vis[i]) topsort(i);
    }

    reverse(topo.begin(), topo.end());
    for (int i = 0 ; i < n ; ++ i)
        where[topo[i]] = i + 1;

    if (!ok) return cout << "NO\n", void();

    cout << "YES\n";
    for (auto [u, v] : un) {
        if (where[u] < where[v]) {
            cout << u << ' ' << v << '\n';
        } else cout << v << ' ' << u << '\n';
    }

    for (auto [u, v] : di)
        cout << u << ' ' << v << '\n';
}

int main () {
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    while (t -- ) {
        solve();
        for (int i = 1 ; i <= n ;++ i) {
            a[i].clear();
            d[i] = 0;
            vis[i] = false;
        }
        topo.clear();
    }

}