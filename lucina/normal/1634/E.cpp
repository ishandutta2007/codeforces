#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int m;
string ans[nax];
map <int, int> f[nax];
map <int, int> to_id;
int remap[nax];
void add(int x) {
    if (!to_id.count(x)) {
        int sz = to_id.size();
        remap[sz] = x;
        to_id[x] = sz;
    }
}
vector <int> g[nax];
bool vis[nax];
bool odds[nax];
/**
* It's quite a long time since I last used this eulertour template
* the last time might be around round 5xx or early 6xx
* 
*/
struct Eulertour {
    vector <vector <pair < int, int>>> a;
    vector <int> deg;
    vector <int> pt;
    vector <pair < int, int>> edge;
    vector <bool> rem;
    int n;
    int id = 0;

    void add_edge(int u,int v){
        a[u].push_back({v, ++id});
        a[v].push_back({u, id});
        ++ deg[u]; ++ deg[v];
    }

    Eulertour(int _n){
        n = _n;
        a.resize(n + 5);
        deg.resize(n + 5, 0);
        pt.resize(n + 5, 0);
        rem.resize(n + 10, false);
    }
    pair <bool, int> ok(bool tour) {
        int odd = 0;
        int mark = 1;
        for (int i = 1; i <= n; ++ i) {
            if (deg[i] & 1){
                ++ odd;
                mark = i;
            }
        }
        return tour ? make_pair(odd == 0, mark) : make_pair(((odd == 2)||(odd == 0)), mark);
    }
    vector <pair <int, int>> tour(int nod) {
        vector <int> path;
        vector <int> st;
        vector <pair < int, int>> edges;
        st.push_back(nod);
        vector <pair < int, int>> res_edges;
        while(!st.empty()){
            int p = st.back();
            vis[p] = true;
            int q = -1;
            int r;
            while(pt[p] < deg[p] && q ==- 1){
                if(!rem[a[p][pt[p]].second]){
                    q = a[p][pt[p]].first;
                    r = pt[p];
                    rem[a[p][pt[p]].second] = true;
                }
                ++ pt[p];
            }
            if(q == -1){
                st.pop_back(); // path.push_back(p);
                if (!edges.empty()) res_edges.push_back(edges.back()), edges.pop_back();
            } else {
                st.push_back(q);
                edges.emplace_back(p, q);
            }
        }
        return res_edges;
    }
};




Eulertour E(nax);

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> m;
    for (int i = 1 ; i <= m ; ++ i) {
        int n;
        cin >> n;
        map <int, int> &foo = f[i];
        ans[i].resize(n);
        for (int j = 0 ; j < n ; ++ j) {
            int x;
            cin >> x;
            add(x);
            if (foo.count(x)) {
                ans[i][foo[x]] = 'L';
                ans[i][j] = 'R';
                foo.erase(x);
            } else foo[x] = j;
        }
    }

    for (int i = 1 ; i <= m ; ++ i) {
        for (auto &[values, _] : f[i]) {
            int id = to_id[values];
            odds[m + id + 1] ^= 1;
            odds[i] ^= 1;
            E.add_edge(i, m + id + 1);
        }
    }
    for (int i = 0 ; i < nax ; ++ i)
        if (odds[i]) {
            cout << "NO\n";
            return 0;
        }

    for (int p = 1 ; p < nax ; ++ p) {
        if (!vis[p]) {
            vector <pair <int, int>> tour = E.tour(p);
            for (int i = 0 ; i < tour.size() ; ++ i) {
                auto [u, v] = tour[i];
                int rows = min(u, v);
                int values = max(u, v) - m - 1;
                int where = f[rows][remap[values]];
                ans[rows][where] = (i % 2 ? 'L' : 'R');
            }
        }
    }

   cout << "YES\n";
    for (int i = 1 ; i <= m ; ++ i)
        cout << ans[i] << '\n';
}
/*
    Alphacode!?
*/