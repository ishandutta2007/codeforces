#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second

const int N = 2e4 + 10;

struct edge {
    int to, cap, flow;
};

int S = N - 2, T = N - 1;
vector <int> g[N];
vector<edge> edges;

void addedge(int a, int b, int cap) {
//    cout << "add "<< a << ' ' << b << ' ' << cap << endl;
    g[a].push_back(edges.size());
    edges.push_back({b, cap, 0});
    g[b].push_back(edges.size());
    edges.push_back({a, 0, 0});
}

int lvl[N];
int q[N], qs, qf;

bool bfs() {
    for(int i = 0; i < N; ++i) {
        lvl[i] = -1;
    }
    lvl[S] = 0;
    qf = qs = 0;
    q[qf++] = S;
    while(qs<qf) {
        int v = q[qs++];
        for(auto idx: g[v]) {
            if(edges[idx].flow != edges[idx].cap) {
                if (lvl[edges[idx].to]==-1){
                    lvl[edges[idx].to]=lvl[v]+1;
                    q[qf++]=edges[idx].to;
                }
            }
        }
    }
    return lvl[T]!=-1;
}
int ptr[N];

int dfs(int v,int flow) {
    if (flow == 0 || v == T) return flow;
    for(int &i = ptr[v]; i < g[v].size(); ++i) {
        int e=g[v][i];
        if(lvl[edges[e].to]==lvl[v] + 1) {
            int ret=dfs(edges[e].to, min(flow, edges[e].cap - edges[e].flow));
            if(ret>0){
                edges[e].flow+=ret;
                edges[e^1].flow-=ret;
                return ret;
            }
        }
    }
    return 0;
}

int n, m;

int maxflow(int x) {
    for(auto &e:edges) e.flow=0;
    for(auto &e: g[S]) {
        edges[e].cap = x;
    }
//    for(int i = 0; i < N; ++i) {
//        for(auto x: g[i]) {
//            cout << i << ' ' << edges[x].to << ' ' << edges[x].cap << endl;
//        }
//    }
    int ret = 0;
    while(bfs()){
        memset(ptr, 0, sizeof ptr);
        while(true) {
            int val = dfs(S, 10000000);
            if(val == 0) break;
            ret += val;
        }
    }
    return ret;
}

int a[N], b[N];

int main() {
//    ifstream cin( "input.txt" );
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        addedge(S, i, 0);
    }
    for(int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        addedge(x, n + i, 1);
        addedge(y, n + i, 1);
        addedge(n + i, T, 1);
        a[i] = x, b[i] = y;
    }
//    cout << maxflow(m) << endl;
//    return 0;
    int lf = 0, rg = m;
    while(rg - lf > 1) {
        int md = (lf + rg) / 2;
        if(maxflow(md) == m) rg= md;
        else lf = md;
    }
    maxflow(rg);
    cout << rg << endl;
    for(int i = 1; i <= n; ++i) {
        for(int e: g[i]) {
            edge t = edges[e];
            int idx = edges[e].to - n;
            if(t.flow==1){

                cout << i << ' ' << (i ^ a[idx] ^ b[idx]) << '\n';
            }
        }
    }
}