#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 500000 + 10;

struct edge{
    int u, v, w;
} E[maxn];

int where[maxn];
int order[maxn];

int ds[maxn];
bool ok[maxn];

int query[maxn];

pii update[2 * maxn];
int counter;

int root(int a){
    return ds[a] < 0 ? a : root(ds[a]);
}

bool join(int a, int b){
    a = root(a), b = root(b);

    if (a == b) return false;

    if (ds[a] < ds[b]) swap(a, b);

    update[counter++] = pii(a, ds[a]);
    update[counter++] = pii(b, ds[b]);

    ds[b] += ds[a];
    ds[a] = b;

    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        E[i] = {u, v, w};
        order[i] = i;
    }

    sort(order, order + m, [&](int u, int v){
        return E[u].w < E[v].w;
    });

    for (int i = 0; i < m; ++i)
        where[order[i]] = i;

    memset(ds, -1, sizeof ds);

    // for (int i = 0, j; i < m; i = j){
    //     for (j = i; j < m && E[order[j]].w == E[order[i]].w; ++j){
    //         int u = E[order[j]].u, v = E[order[j]].v;

    //         if (root(u) != root(v))
    //             ok[order[j]] = true;
    //     }

    //     for (j = i; j < m && E[order[j]].w == E[order[i]].w; ++j){
    //         int u = E[order[j]].u, v = E[order[j]].v;
    //         merge(u, v);
    //     }
    // }

    int q; cin >> q;

    vector<pii> qedges;

    for (int j = 0; j < q; ++j){
        int sz; cin >> sz;
        query[j] = sz;

        for (int i = 0; i < sz; ++i){
            int idx; cin >> idx;
            idx--;
            qedges.push_back({idx, j});
        }
    }

    sort(qedges.begin(), qedges.end(), [&](pii a, pii b){
        if (E[a.first].w != E[b.first].w) return E[a.first].w < E[b.first].w;
        return a.second < b.second;
    });

    auto pred = [&](pii a, pii b){
        return a.second == b.second && E[a.first].w == E[b.first].w;
    };

    int cur = 0;

    for (int i = 0, j; i < (int)qedges.size(); i = j){
        while (cur < m && E[order[cur]].w < E[qedges[i].first].w){
            join(E[order[cur]].u, E[order[cur]].v);
            cur++;
        }

        int curcounter = counter;

        for (j = i; j < (int)qedges.size() && pred(qedges[j], qedges[i]); ++j){
            auto e = E[qedges[j].first];

            if (join(e.u, e.v)){
                query[qedges[j].second]--;
            }
        }

        while (counter > curcounter){
            counter--;
            ds[update[counter].first] = update[counter].second;
        }
    }

    for (int i = 0; i < q; ++i)
        cout << (query[i] == 0 ? "YES" : "NO") << endl;

    return 0;
}