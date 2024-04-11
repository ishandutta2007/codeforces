#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define MP make_pair
#define F first
#define S second

const int N = (int)2e5;
vector<int> g[N];
vector<pii> ver;
set<pii> was;
vector<int> ansa, ansb, ansc;
vector<bool> u;
int hei[N];

void dfs(int v, int hh)
{
    u[v] = true;
    hei[v] = hh;
    ver.push_back(pii(-hh, v));
    for (int to : g[v])
        if (!u[to])
            dfs(to, hh + 1);
}

pii edge(int a, int b)
{
    if (a > b)
        swap(a, b);
    return pii(a, b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if (m % 2)
    {
        cout << "No solution";
        return 0;
    }
    u.assign(n, 0);
    dfs(0, 0);
    sort(ver.begin(), ver.end());
    for (int i = 0; i < ver.size(); i++)
    {
        int v = ver[i].S;
        int pa = -1;
        vector<pii> kids;
        for (int to : g[v])
            kids.push_back(pii(-hei[to], to));
        sort(kids.begin(), kids.end());
        for (pii t : kids)
        {
            int to = t.S;
            pii cur = edge(v, to);
            if (was.count(cur))
                continue;
            if (pa == -1)
            {
                pa = to;
                continue;
            }
            pii old = edge(pa, v);
            was.insert(old);
            was.insert(cur);
            ansa.push_back(pa + 1);
            ansb.push_back(v + 1);
            ansc.push_back(to + 1);
            pa = -1;
        }
    }
    for (int i = 0; i < ansa.size(); i++)
        cout << ansa[i] << " " << ansb[i] << " " << ansc[i] << "\n";

    return 0;
}