#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> PLL;
typedef long long LL;
typedef long double ld;
#define MP make_pair
#define F first
#define S second

#ifdef TEST
    class Timer
    {
    public:
        Timer()
        {
            start = clock();
        }

        ~Timer()
        {
            cerr << "Execution time: " << clock() - start << " ms" << endl;
        }
    private:
        int start;
    };

    Timer timer;
#endif

struct Dsu
{
    vector<int> p;
    vector<int> sz;

    void init(int n)
    {
        p.resize(n);
        sz.assign(n, 1);
        for (int i = 0; i < n; i++)
            p[i] = i;
    }

    int get(int v)
    {
        return p[v] == v ? v : p[v] = get(p[v]);
    }

    void unite(int a, int b)
    {
        a = get(a);
        b = get(b);
        p[a] = b;
        sz[b] += sz[a];
    }
};

struct edge
{
    int fr, to, w;
    edge(int f, int t, int _w): fr(f), to(t), w(_w) {}
};

bool operator < (const edge &a, const edge &b)
{
    return a.w > b.w;
}

vector<edge> e;
Dsu tree;

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        int w = min(a[u], a[v]);
        e.push_back(edge(u, v, w));
    }
    tree.init(n);
    sort(e.begin(), e.end());
    long long up = 0;
    long long down = n * 1ll * (n - 1) / 2;
    for (edge x : e)
    {
        int u = x.fr;
        int v = x.to;
        int w = x.w;
        u = tree.get(u);
        v = tree.get(v);
        if (u == v)
            continue;
        long long s1 = tree.sz[u];
        long long s2 = tree.sz[v];
        up += s1 * s2 * w;
        tree.unite(u, v);
    }

    cout.setf(ios::fixed);
    cout.precision(10);
    cout << up * 1. / down;

    return 0;
}