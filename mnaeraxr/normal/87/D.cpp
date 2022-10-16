#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int64> vi;

const int64 oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int64 maxn = 100010;

struct edge{
    int64 u, v, w, idx;

    bool operator <(const edge &e) const{
        return w < e.w;
    }
};

struct disjoint_set{
    int64 n;
    vector<int64> ds;

    disjoint_set(int64 n) : n(n){
        ds = vector<int64>(n, -1);
    }

    int64 root(int64 a){
        return ds[a] < 0 ? a : ds[a] = root(ds[a]);
    }

    bool join(int64 u, int64 v){
        u = root(u), v = root(v);
        if (u == v) return true;

        if (ds[u] > ds[v]) swap(u, v);
        ds[u] += ds[v];
        ds[v] = u;

        return true;
    }

    int64 size(int64 u){
        return -ds[root(u)];
    }
};

struct tree{
    struct node{
        int64 value;
        vector<pair<int64,int64>> adj;
    };

    int n;
    vector<node> nodes;
    vector<int64> children;
    vector<bool> marked;
    vector<int> c_dfs;

    tree(int n) : n(n){
        nodes = vector<node>(n);
        children = vector<int64>(n);
        marked = vector<bool>(n);
    }

    void add_edge(int u, int v, int64 uu, int64 vv, int64 idx){
        nodes[u].value = uu;
        nodes[u].adj.push_back({v, idx});

        nodes[v].value = vv;
        nodes[v].adj.push_back({u, idx});
    }

    void dfs(int64 u){
        children[u] = nodes[u].value;
        marked[u] = true;
        c_dfs.push_back(u);

        for (auto v : nodes[u].adj){
            if (!marked[v.first]){
                dfs(v.first);
                children[u] += children[v.first];
            }
        }
    }

    map<int64,int64> solve(){
        map<int64,int64> ans;

        for (int i = 0; i < n; ++i){
            if (marked[i]) continue;

            c_dfs.clear();

            dfs(i);

            int64 total = children[i];

            for (auto u : c_dfs){
                for (auto e : nodes[u].adj){
                    int64 v = e.first, idx = e.second;

                    int64 m = min(children[u], children[v]);
                    int64 trees = m * (total - m);

                    ans[idx] = trees;
                }
            }
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int64 n; cin >> n;
    vector<edge> E(n - 1);

    disjoint_set ds(n + 1);

    for (int64 i = 0; i < n - 1; ++i){
        cin >> E[i].u >> E[i].v >> E[i].w;
        E[i].idx = i;
    }

    sort(E.begin(), E.end());

    vector<int64> ans(n - 1);

    for (int64 i = 0, j; i < n - 1; i = j){
        // cout << "start stage: " << E[i].w << endl;

        vector<pii> to_join;
        vector<int> cand;

        for (j = i; j < n - 1 && E[j].w == E[i].w; ++j){
            int u = E[j].u, v = E[j].v;
            cand.push_back(ds.root(u));
            cand.push_back(ds.root(v));
        }

        sort(cand.begin(), cand.end());
        cand.resize(unique(cand.begin(), cand.end()) - cand.begin());

        tree T(cand.size());

        for (j = i; j < n - 1 && E[j].w == E[i].w; ++j){
            int64 u = E[j].u, v = E[j].v, idx = E[j].idx;
            u = ds.root(u), v = ds.root(v);

            int iu = lower_bound(cand.begin(), cand.end(), u) - cand.begin();
            int iv = lower_bound(cand.begin(), cand.end(), v) - cand.begin();

            int64 uu = ds.size(u), vv = ds.size(v);
            T.add_edge(iu, iv, uu, vv, idx);

            // cout << "add edge: " << iu << " " << iv << " " << uu << " " << vv << " " << idx << endl;

            to_join.push_back({u, v});

        }

        for (auto r : T.solve()){
            ans[r.first] = r.second;
            // cout << r.first << " " << r.second << endl;
        }

        for (auto p : to_join)
            ds.join(p.first, p.second);

        // cout << "End stage" << endl;
        // cout << endl;
    }

    int64 M = *max_element(ans.begin(), ans.end());

    vector<int64> valid;
    for (int64 i = 0; i < n - 1; ++i)
        if (ans[i] == M) valid.push_back(i + 1);

    cout << 2 * M << " " << valid.size() << endl;
    for (auto a : valid)
        cout << a << " ";
    cout << endl;

    return 0;
}