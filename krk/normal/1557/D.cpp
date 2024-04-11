#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 300005;
const int Maxm = 4194304;

int n, m;
vector <ii> V[Maxn];
vector <int> un;
int par[Maxn];
ii mx[Maxm], fl[Maxm];
vector <int> res;

void downOn(int v, ii f)
{
    mx[v] = max(mx[v], f);
    fl[v] = max(fl[v], f);
}

void Down(int v)
{
    if (fl[v] != ii(0, 0)) {
        downOn(2 * v, fl[v]);
        downOn(2 * v + 1, fl[v]);
        fl[v] = ii(0, 0);
    }
}

void Union(int v)
{
    mx[v] = max(mx[2 * v], mx[2 * v + 1]);
}

ii Get(int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return mx[v];
    else {
        int m = l + r >> 1;
        Down(v);
        ii res = ii(0, 0);
        if (a <= m) res = max(res, Get(2 * v, l, m, a, min(m, b)));
        if (m + 1 <= b) res = max(res, Get(2 * v + 1, m + 1, r, max(m + 1, a), b));
        return res;
    }
}

void Update(int v, int l, int r, int a, int b, ii val)
{
    if (l == a && r == b) downOn(v, val);
    else {
        int m = l + r >> 1;
        Down(v);
        if (a <= m) Update(2 * v, l, m, a, min(m, b), val);
        if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
        Union(v);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int row, l, r; scanf("%d %d %d", &row, &l, &r);
        V[row].push_back(ii(l, r));
    }
    for (int row = 1; row <= n; row++) {
        vector <ii> tmp;
        sort(V[row].begin(), V[row].end());
        for (int j = 0; j < V[row].size(); j++)
            if (tmp.empty() || tmp.back().second + 1 < V[row][j].first)
                tmp.push_back(V[row][j]);
            else tmp.back().second = max(tmp.back().second, V[row][j].second);
        V[row] = tmp;
        for (int j = 0; j < V[row].size(); j++) {
            un.push_back(V[row][j].first);
            un.push_back(V[row][j].second);
        }
    }
    sort(un.begin(), un.end());
    un.erase(unique(un.begin(), un.end()), un.end());
    for (int i = 1; i <= n; i++) {
        ii cand = ii(0, 0);
        for (int j = 0; j < V[i].size(); j++) {
            int lef = lower_bound(un.begin(), un.end(), V[i][j].first) - un.begin();
            int rig = lower_bound(un.begin(), un.end(), V[i][j].second) - un.begin();
            cand = max(cand, Get(1, 0, int(un.size()) - 1, lef, rig));
        }
        par[i] = cand.second;
        cand.first++; cand.second = i;
        for (int j = 0; j < V[i].size(); j++) {
            int lef = lower_bound(un.begin(), un.end(), V[i][j].first) - un.begin();
            int rig = lower_bound(un.begin(), un.end(), V[i][j].second) - un.begin();
            Update(1, 0, int(un.size()) - 1, lef, rig, cand);
        }
    }
    par[n + 1] = Get(1, 0, int(un.size()) - 1, 0, int(un.size()) - 1).second;
    int v = n + 1;
    while (v) {
        for (int i = v - 1; i > par[v]; i--)
            res.push_back(i);
        v = par[v];
    }
    printf("%d\n", int(res.size()));
    for (int i = int(res.size()) - 1; i >= 0; i--)
        printf("%d%c", res[i], i - 1 >= 0? ' ': '\n');
    return 0;
}