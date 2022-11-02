#include <bits/stdc++.h>

using namespace std;

const int N = 1000 * 1000;

vector<int> g[N];
vector<bool> u(N, false);

vector<int> add[N];
vector<int> del[N];
vector<int> ask[N];

multiset<int> tin;
multiset<int> *tout[N];

int res[N];
int f[N];
int n;

void dfs(int v)
{
    u[v] = true;
    for (auto t: add[v])
        tin.insert(t);
    for (auto t: ask[v])
    {
        auto good = tin.upper_bound(t);
        if (good == tin.begin())
            f[t] = -1;
        else
            f[t] = *(--good);
    }

    vector<int> ch;
    for (auto to: g[v])
        if (!u[to])
        {
            dfs(to);
            ch.push_back(to);
        }

    if (ch.size() == 0)
        tout[v] = new multiset<int> ();
    else
    {
        int j = ch[0];
        for (auto c: ch)
            if (tout[c]->size() > tout[j]->size())
                j = c;
        tout[v] = tout[j];
        for (auto c: ch)
            if (c != j)
            {
                for (auto val: (*tout[c]))
                    (*tout[v]).insert(val);
                tout[c]->clear();
            }
    }
    for (auto t: del[v])
        tout[v]->insert(t);
    for (auto t: ask[v])
    {
        if (f[t] == -1)
        {
            res[t] = 0;
            continue;
        }
        auto bad = tout[v]->upper_bound(f[t]);
        if (bad == tout[v]->end() || *bad > t)
            res[t] = 1;
        else
            res[t] = 0;
    }
    for (auto t: add[v])
        tin.erase(tin.find(t));
}

int main()
{
    ios_base::sync_with_stdio(0);
    #if defined DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int q;
    cin >> q;

    fill(res, res + q, -1);

    for (int i = 0; i < q; i++)
    {
        int t, v;
        cin >> t >> v;

        v--;

        if (t == 1)
            add[v].push_back(i);
        if (t == 2)
            del[v].push_back(i);
        if (t == 3)
            ask[v].push_back(i);
    }

    dfs(0);

    for (int i = 0; i < q; i++)
        if (res[i] >= 0)
            cout << res[i] << "\n";

    return 0;
}