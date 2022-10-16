#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int ask(int u, int v)
{
    cout << "? " << u << " " << v << endl;
    cout.flush();
    int lca;
    cin >> lca;
    return lca;
}

void fin(int r)
{
    cout << "! " << r << endl;
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);

    for (int i = 0; i + 1 < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int c = 1;
    int tree_size, fancy_node;
    function<void(int, int)> go = [&](int s, int p) {
        if (p == -1)
            tree_size = 0;
        tree_size++;

        if (tree[s].size() >= 2)
            fancy_node = s;

        for (auto u : tree[s])
        {
            if (u == p)
                continue;
            go(u, s);
        }
    };

    auto remove_edge = [&](int u, int v) {
        for (int i = 0; i < tree[u].size(); ++i)
        {
            if (tree[u][i] == v)
            {
                swap(tree[u][i], tree[u].back());
                break;
            }
        }

        tree[u].pop_back();
    };

    while (true)
    {
        go(c, -1);

        if (tree_size == 1)
        {
            fin(c);
        }

        if (tree_size == 2)
        {
            int l = ask(c, tree[c][0]);
            fin(l);
        }

        int u = tree[fancy_node][0];
        int v = tree[fancy_node][1];
        int l = ask(u, v);

        if (l == u)
        {
            remove_edge(u, fancy_node);
        }
        else if (l == v)
        {
            remove_edge(v, fancy_node);
        }
        else
        {
            remove_edge(fancy_node, u);
            remove_edge(fancy_node, v);
        }

        c = l;
    }

    return 0;
}