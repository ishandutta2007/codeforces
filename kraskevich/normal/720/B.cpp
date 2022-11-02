#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct maximalFlow
{
    struct edge
    {
        int to, capacity, flow, rev;

        edge() {}
        edge(int _to, int _capacity, int _rev)
        {
            to = _to;
            capacity = _capacity;
            flow = 0;
            rev = _rev;
        }

        void pushFlow(int addFlow)
        {
            flow += addFlow;
        }

        bool isOpen(int minimum)
        {
            return capacity - flow >= minimum;
        }
    };

    vector<int> good;
    vector<vector<edge> > graph;
    vector<int> distance;
    int currentMinimum;
    int start;
    int fin;
    const static long long inf = 1000 * 1000 * 1000;

    bool dfs(int v)
    {
        if (v == fin)
            return true;
        if (distance[v] >= distance[fin])
            return false;
        for (; good[v] < graph[v].size(); ++good[v])
            if (graph[v][good[v]].isOpen(currentMinimum) && distance[graph[v][good[v]].to] == distance[v] + 1 &&
                dfs(graph[v][good[v]].to))
                return true;
        return false;
    }

    bool bfs()
    {
        int n = graph.size();
        distance.assign(n, inf);
        distance[start] = 0;
        queue<int> q;
        q.push(start);

        while (!q.empty())
        {
            int v = q.front();
            if (v == fin)
                break;
            q.pop();
            for (int i = 0; i < graph[v].size(); ++i)
            {
                int to = graph[v][i].to;
                if (graph[v][i].isOpen(currentMinimum) && distance[to] > distance[v] + 1)
                {
                    distance[to] = distance[v] + 1;
                    q.push(to);
                }
            }
        }

        return distance[fin] != inf;
    }

    void pushFlow()
    {
        int addFlow = inf;
        for (int i = start; i != fin; i = graph[i][good[i]].to)
            addFlow = min(addFlow, graph[i][good[i]].capacity - graph[i][good[i]].flow);

        for (int i = start; i != fin; i = graph[i][good[i]].to)
        {
            graph[i][good[i]].pushFlow(addFlow);
            int to = graph[i][good[i]].to;
            int id = graph[i][good[i]].rev;
            graph[to][id].pushFlow(-addFlow);
        }
    }

    void initialize(int n)
    {
        graph.resize(n);
        for (int i = 0; i < n; ++i)
            graph[i].clear();
    }

    void addEdge(int from, int to, int capactiy)
    {
        int sizeFrom = graph[from].size();
        int sizeTo = graph[to].size();
        graph[from].push_back(edge(to, capactiy, sizeTo));
        graph[to].push_back(edge(from, 0, sizeFrom));
    }

    long long getMaximalFlow(int _start, int _fin)
    {
        start = _start;
        fin = _fin;
        currentMinimum = 1;//(1 << 30);
        int n = graph.size();
        for (;currentMinimum > 0; currentMinimum /= 2)
            while (bfs())
            {
                good.assign(n, 0);
                while (dfs(start))
                    pushFlow();
            }
        long long flow = 0;
        for (int i = 0; i < graph[start].size(); ++i)
            flow += (long long)graph[start][i].flow;
        return flow;
    }

};

const int N = 20 * 1000 + 10;

vector<int> g[N];
vector<int> col[N];
int par[N];
int parCol[N];
bool was[N];
set<pii> cyclic;
vector<int> fr;
vector<int> to;
vector<int> edge_col;

void dfs(int v, int p, int pc) {
    was[v] = true;
    parCol[v] = pc;
    par[v] = p;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        int c = col[v][i];
        if (!was[to] && to != p) 
            dfs(to, v, c);
    }
}


pii makeEdge(int a, int b) {
    if (a > b)
        swap(a, b);
    return pii(a, b);
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        --c;
        g[a].push_back(b);
        g[b].push_back(a);
        col[a].push_back(c);
        col[b].push_back(c);
        fr.push_back(a);
        to.push_back(b);
        edge_col.push_back(c);
    }
    vector<vector<int>> colors;
    for (int i = 0; i < m; i++) {
        int a = fr[i];
        int b = to[i];
        int c = edge_col[i];
        if (cyclic.count(makeEdge(a, b)))
            continue;
        fill(was, was + n, false);
        dfs(b, a, c);
        vector<int> cur;
        cur.push_back(c);
        cyclic.insert(makeEdge(a, b));
        if (!was[a]) {
            colors.push_back(cur);
            continue;
        }
        int v = a;
        while (v != b) {
            cur.push_back(parCol[v]);
            cyclic.insert(makeEdge(v, par[v]));
            v = par[v];
        }
        colors.push_back(cur);                                
    }             
    set<int> mustHave;
    vector<bool> done(colors.size());
    for (int i = 0; i < colors.size(); i++) {
        bool any = false;
        for (int j = 0; j < colors.size(); j++) {         
            if (done[j])
                continue;
             if (colors[j].size() == 1) {
                done[j] = true;
                mustHave.insert(colors[j][0]);
                any = true;
             } else {
                set<int> diff;  
                bool ok = false;
                for (int x : colors[j])
                    if (diff.count(x) || mustHave.count(x)) {
                        ok = true;
                        break;
                    } else {
                        diff.insert(x);
                    }
                if (ok) {
                    any = true;
                    done[j] = true;
                    for (int x : colors[j])
                        mustHave.insert(x);
                }
             }         
        }
        if (!any)
            break;                   
    }
    vector<vector<int>> hard;
    for (int i = 0; i < colors.size(); i++)
        if (!done[i])     
            hard.push_back(colors[i]);
    if (hard.size() == 0) {
        cout << mustHave.size() << endl;
        return 0;
    }
    maximalFlow G;
    int L = m;
    int R = hard.size();
    G.initialize(L + R + 2);
    int st = 0;
    int en = L + R + 1;
    for (int i = 1; i <= L; i++)
        G.addEdge(st, i, 1);
    for (int i = 0; i < hard.size(); i++) {
        int rv = L + 1 + i;
        G.addEdge(rv, en, (int) hard[i].size() - 1);
        for (int c : hard[i])
            G.addEdge(c + 1, rv, 1);
    }
    cout << mustHave.size() + G.getMaximalFlow(st, en) << endl;                 
    return 0;
}