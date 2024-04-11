#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <utility>

using namespace std;

map<string,string> M;

typedef long long int64;

int gcd(int a, int b){
    return a == 0 ? b : gcd(b % a, a);
}

int f(int a, int b)
{
    int g = gcd(a, b);
    int ans = 0;
    for (int i = 2; i * i <= g; ++i)
    {
        while (g % i == 0){
            g /= i;
            ans++;
        }
    }
    return ans;
}


const int oo =  1 << 20;

namespace Dinic{
    struct edge{
        int dest, cap, flow, next;
        edge() {};
        edge(int dest, int cap, int next) : dest(dest), cap(cap), next(next)
        {
            flow = 0;
        }
    };
    const int MAXV = 1005;
    const int MAXE = 1000000;
    int Q[MAXV], lo, hi;
    int nodes, source, sink, size;
    int dst[ MAXV ];
    int ptr[ MAXV ];
    edge g[MAXE];
    int first[MAXV];
    void initialize(int __nodes, int __source, int __sink){
        size = 0;
        nodes = __nodes;
        source = __source;
        sink = __sink;
        for (int i = 0; i < nodes; ++i) first[i] = -1;
    }
    void add_edge(int u, int v, int c){
        //cout << "EDGE " <<  u << " " << v << " " << c << endl;
        g[ size ] = edge(v, c, first[u]);
        first[u] = size++;
        g[ size ] = edge(u, 0, first[v]);
        first[v] = size++;
    }
    bool bfs()
    {
        lo = 0; hi = 0;
        for (int i = 0; i < nodes; ++i)
            dst[i] = -1;
        dst[ source ] = 0;
        for (Q[ hi++ ] = source; lo < hi; ++lo){
            int u = Q[ lo ];
            for (int k = first[ u ]; k != -1; k = g[ k ].next){
                int w = g[k].dest;
                if (g[k].cap > g[k].flow && dst[w] == -1){
                    dst[w] = dst[u] + 1;
                    Q[hi++] = w;
                }
            }
        }
        return dst[sink] != -1;
    }

    int dfs(int u, int flow){
        if (!flow) return 0;
        if (u == sink) return flow;
        for (int &k = ptr[u]; k != -1; k = g[k].next){
            int w = g[k].dest;
            int cf = g[k].cap - g[k].flow;
            if (dst[u] + 1 != dst[w]) continue;
            int pushed = dfs(w, min(flow, cf));
            if (pushed){
                g[k].flow += pushed;
                g[k^1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }
    int dinic(){
        int flow = 0;
        while (true){
            if (!bfs()) break;
            for (int i = 0; i < nodes; ++i) ptr[i] = first[i];
            while (int pushed = dfs(source, oo)) flow += pushed;
        }
        return flow;
    }
}

int main()
{

    vector<int> V;
    vector< map<int,int> > F;

    int n, m; cin >> n >> m;

    F.resize(n);

    Dinic::initialize( 10 * n + 2, 0, 1);

    int cur = 2;

    for (int i = 0; i < n; ++i)
    {
        int v; cin >> v;
        V.push_back(v);
        if (i & 1)
        {
            for (int j = 2; j * j <= v; ++j)
            {
                if (v % j == 0)
                {
                    int cnt = 0;
                    while (v % j == 0)
                    {
                        cnt++;
                        v /= j;
                    }
                    F[i][j] = cur;
                    Dinic::add_edge(0, cur, cnt);
                    cur++;
                }
            }
            if (v > 1)
            {
                F[i][v] = cur;
                Dinic::add_edge(0, cur, 1);
                cur++;

            }
        }
        else
        {
            for (int j = 2; j * j <= v; ++j)
            {
                if (v % j == 0)
                {
                    int cnt = 0;
                    while (v % j == 0)
                    {
                        cnt++;
                        v /= j;
                    }
                    F[i][j] = cur;
                    Dinic::add_edge(cur, 1, cnt);
                    cur++;
                }
            }

            if (v > 1)
            {
                F[i][v] = cur;
                Dinic::add_edge(cur, 1, 1);
                cur++;

            }
        }
    }

    for (int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        a--; b--;
        if (b & 1) swap(a, b);
        int g = gcd(V[a], V[b]);

        for (int j = 2; j * j <= g; ++j)
        {
            if (g % j == 0)
            {
                int cnt = 0;
                while (g % j == 0)
                {
                    ++cnt;
                    g /= j;
                }
                if (V[a] % j == 0 && V[b] % j == 0)
                    Dinic::add_edge(F[a][j], F[b][j], cnt);
            }
        }

        if (g > 1 && V[a] % g == 0 && V[b] % g == 0)
        {
            Dinic::add_edge(F[a][g],F[b][g], 1);

        }

    }

    cout << Dinic::dinic() << endl;
}