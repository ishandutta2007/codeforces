#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
using namespace std;

const int N = 100005;

int n, m, c, q, u, v, cnt = 0;
char t;
map<pair<int, int>, int> ind;
vector<int> dsu;
vector<set<int>> odd;

int get(int u, int c)
{
    if (ind.count({u, c}) == 0)
    {
        ind[{u, c}] = cnt++;
        dsu.push_back(-1);
        odd.push_back({});
    }
    return ind[{u, c}];
}

int trace(int u)
{
    return dsu[u] < 0 ? u : dsu[u] = trace(dsu[u]);
}

void connect(int u, int v)
{
    if ((u = trace(u)) == (v = trace(v)))
        return;
    if (dsu[u] > dsu[v])
        swap(u, v);
    dsu[u] += dsu[v];
    dsu[v] = u;
    if (odd[u].size() < odd[v].size())
        swap(odd[u], odd[v]);
    for (int ele : odd[v])
        odd[u].insert(ele);
    odd[v].clear();
}

void add(int u, int v)
{
    u = trace(u);
    odd[u].insert(v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> c >> q;
    for (int i = 1; i <= n; i++)
        get(i, 0);
    while (m--)
    {
        cin >> u >> v >> c;
        int l = get(u, c), r = get(v, c);
        add(l, u); add(r, v);
        connect(l, get(v, 0)); connect(r, get(u, 0));
    }
    while (q--)
    {
        cin >> t >> u >> v;
        if (t == '?')
        {
            if (trace(get(u, 0)) == trace(get(v, 0)))
                cout << "Yes\n";
            else if (odd[trace(get(u, 0))].count(v) == 1)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        else
        {
            cin >> c;
            int l = get(u, c), r = get(v, c);
            add(l, u); add(r, v);
            connect(l, get(v, 0)); connect(r, get(u, 0));
        }
    }
}