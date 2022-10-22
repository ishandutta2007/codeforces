#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int, int > pii;
typedef long long ll;

const int inf = 1e9;
ll const inf64 = 1ll * inf * inf;

const int N = 1e5 + 5;

int n, m;
int c[N];
ll balance[N];
pii edge[N];
vec< int > g[N];
int color[N];
int parent[N];
int st, fn, ed;

inline int get_to(int id, int v) {
    return edge[id].first == v ? edge[id].second : edge[id].first;
}

void dfs(int v, int cl) {
    color[v] = cl;
    for(int id : g[v]) {
        int to = get_to(id, v);
        if(!color[to]) {
            parent[to] = id;
            dfs(to, 3 - cl);
        }else if(color[to] == color[v] && !st) {
            st = to;
            fn = v;
            ed = id;
        }
    }
}

bool check_bi(vec< int >& cycle) {
    dfs(1, 1);
    if(!st) return false;
    cycle.push_back(ed);
    for(int u = fn;u != st;) {
        int id = parent[u];
        int v = get_to(id, u);
        cycle.push_back(id);
        u = v;
    }
    return true;
}

ll res[N];
int used[N];

void go(int v) {
    used[v] = 1;
    for(int id : g[v]) {
        int to = get_to(id, v);
        if(!used[to]) {
            go(to);
            res[id] = -balance[to];
            balance[v] -= balance[to];
        }
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &c[i]);
        balance[i] = -c[i];
    }

    for(int u, v, i = 0;i < m;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(i);
        g[v].push_back(i);
        edge[i] = make_pair(u, v);
    }

    vec< int > cycle;
    int root = 1;
    bool have_cycle = check_bi(cycle);

    if(have_cycle) {
        root = st;
    }

    go(root);

    if(!have_cycle && balance[root] != 0 || have_cycle && balance[root] % 2) {
        puts("NO");
        return 0;
    }

//    cout << "c = ";
//    for(int id : cycle) {
//        cout << id << " ";
//    }
//    cout << "\n";

//    cout << "root = " << root << "\n";

//    for(int i = 1;i <= n;i++) {
//        cout << balance[i] << " \n"[i == n];
//    }

    ll delt = -balance[root] / 2;

    for(int id : cycle) {
        res[id] += delt;
        delt = -delt;
    }

    puts("YES");

    for(int i = 0;i < m;i++) {
#ifdef debug
        printf("%lld\n", res[i]);
#else
        printf("%I64d\n", res[i]);
#endif
    }

    return 0;
}