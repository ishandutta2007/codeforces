/*
 *      2-Sat
 *      Ring Road 2 (Codeforce)
 */
#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout << #x << "=" << x << endl
#define MP make_pair

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int MAXN = (int)1e5 + 10;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-7;
const int oo = 1 << 30;

namespace sat
{
    const int MAXN = 100010;
    bool v[MAXN];
    int ng[MAXN], sz;
    vi g[MAXN], gt[MAXN], order;
    bool mk[MAXN];
    int scc[MAXN];

    void init()
    {
        sz = 1;
    }

    int new_node()
    {
        int x = sz++;
        ng[x] = sz++;
        ng[ ng[x] ] = x;
        g[x].clear(), gt[x].clear();
        g[ ng[x] ].clear(), gt[ ng[x] ].clear();
        return x;
    }

    int neg(int x){
        return ng[x];
    }

    void dfs(int v){
        mk[v] = true;
        for (int i = 0; i < (int)g[v].size(); ++i){
            if (!mk[ g[v][i] ])
                dfs( g[v][i] );
        }
        order.push_back(v);
    }
    void dfs(int v, int c){
        mk[v] = true;
        scc[v] = c;
        for (int i =0; i < (int)gt[v].size(); ++i){
            if (!mk[ gt[v][i] ])
                dfs(gt[v][i], c);
        }
    }

    void add_edge(int a, int b){
        g[a].push_back(b);
        gt[b].push_back(a);
    }

    void implication(int a, int b){
        add_edge(a, b);
        add_edge(neg(b), neg(a));
    }

    void isor(int a, int b){
        implication(neg(a), b);
    }

    bool solve(){
        order.clear();
        memset(mk, 0, sizeof mk);
        for (int i = 1; i < sz; ++i){
            if (!mk[i]) dfs(i);
        }
        memset(mk, 0, sizeof mk);
        int c = 1;
        for (int i = (int)order.size() - 1; i > -1; --i){
            if (!mk[ order[i] ])
                dfs(order[i], c++);
        }
        for (int i = 1; i < sz; ++i){
            if (scc[i] == scc[neg(i)])
                return false;
            v[neg(i)] = scc[i] < scc[neg(i)];
            v[i] = !v[neg(i)];
        }
        return true;
    }
}

int P[MAXN];
vector<pii> R;

pair<bool, int> parse(string s){
    int n = 0;
    for (int i = 1; i < (int)s.size(); ++i){
        n = 10 * n + s[i] - '0';
    }
    return MP(s[0] == '+', n);
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    sat::init();

    for (int i = 1; i <= n; ++i)
        P[i] = sat::new_node();

    for (int i = 0; i < m; ++i){
        int u, v, s; cin >> u >> v >> s;
        if (s){
            sat::implication(P[u], P[v]);
            sat::implication(sat::neg(P[u]), sat::neg(P[v]));
            sat::implication(P[v], P[u]);
            sat::implication(sat::neg(P[v]), sat::neg(P[u]));
        }
        else{
            sat::implication(P[u], sat::neg(P[v]));
            sat::implication(sat::neg(P[u]), P[v]);
            sat::implication(P[v], sat::neg(P[u]));
            sat::implication(sat::neg(P[v]), P[u]);
        }
    }

    bool ans = sat::solve();
    if (ans){
        vector<int> T;
        for (int i = 1; i <= n; ++i){
            if (sat::v[ P[i] ])
                T.push_back(i);
        }
        cout << T.size() << endl;
        for (int i = 0; i < (int)T.size(); ++i)
            cout << T[i] << " \n"[i == (int)T.size() - 1];
    }
    else{
        cout << "Impossible" << endl;
    }

    return 0;
}