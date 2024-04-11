#include <bits/stdc++.h>

using namespace std;

const int inf = 1000 * 1000 * 1000;

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

    long long getMaximalFlow(int _start, int _fin, int maxCapacity)
    {
        start = _start;
        fin = _fin;
        currentMinimum = 1;
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

const int N = 222;

vector<int> g[N];
vector<int> w[N];
int par[N];
int cost[N];
bool was[N];
int n, m;
maximalFlow mf;

void dfs(int v) {
  was[v] = true;
  for (int i = 0; i < mf.graph[v].size(); i++) {
    auto cur = mf.graph[v][i];
    if (!cur.isOpen(1))
      continue;
    if (!was[cur.to])
      dfs(cur.to);
  }
}

int res = 0;

void build() {
  for (int i = 1; i < n; i++) {
    int p = par[i];
    maximalFlow temp = mf;
    //cerr << i << " " << p << endl;
    cost[i] = mf.getMaximalFlow(i, p, 1);
    res += cost[i];
    fill(was, was + n, false);
    dfs(i);
    /*for (int i = 0; i < n; i++)
      cerr << was[i] << " ";
    cerr << endl;*/
    for (int j = i + 1; j < n; j++)
      if (was[j] && par[j] == p)
        par[j] = i;
    mf = temp;
  }
  for (int i = 1; i < n; i++) {
    int p = par[i];
    int we = cost[i];
    g[p].push_back(i);
    g[i].push_back(p);
    w[i].push_back(we);
    w[p].push_back(we);
  }
}


void dfs2(int v, const vector<int> gg[N], const vector<int> ww[N], int &mn, int &a, int &b) {
  was[v] = true;
  for (int i = 0; i < gg[v].size(); i++) {
    if (was[gg[v][i]])
      continue;
    int to = gg[v][i];
    dfs2(to, gg, ww, mn, a, b);
    if (ww[v][i] < mn) {
      mn = ww[v][i];
      a = v;
      b = to;
    }
  }
}

vector<int> solve(const vector<int> gg[N], const vector<int> ww[N], int v) {
  /*cerr << v << endl;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < gg[i].size(); j++)
      if (gg[i][j] > i)
        cerr << "(" << g[i][j] << " " << i << ") ";
  cerr << endl;*/
  fill(was, was + n, false);
  int mn = inf;
  int a;
  int b;
  dfs2(v, gg, ww, mn, a, b);
  if (mn == inf)
    return vector<int>({v});
  vector<int> g1[N];
  vector<int> w1[N];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < gg[i].size(); j++) {
      int u = gg[i][j];
      if (u == a && i == b || u == b && i == a)
        continue;
      if (!was[i])
        continue;
      g1[i].push_back(u);
      w1[i].push_back(ww[i][j]);
    }
  //cerr << a << " " << b << endl;
  vector<int> l = solve(g1, w1, a);
  vector<int> r = solve(g1, w1, b);
  for (int x : r)
    l.push_back(x);
  return l;
}

int main() {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);

  ios_base::sync_with_stdio(0);

  cin >> n >> m;
  mf.initialize(n);
  for (int i = 0; i < m; i++) {
    int a, b, we;
    cin >> a >> b >> we;
    --a;
    --b;
    mf.addEdge(a, b, we);
    mf.addEdge(b, a, we);
  }
  build();

  vector<int> ans = solve(g, w, 0);
  cout << res << "\n";
  for (int x : ans)
    cout << x + 1 << " ";
   cout << "\n";

  return 0;
}