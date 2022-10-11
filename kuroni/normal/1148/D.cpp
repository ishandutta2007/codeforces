#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 300005;

int n, u, v, f[N], tr[N];

struct TPair
{
    int u, v, ind;

    TPair(int _u = 0, int _v = 0, int _ind = 0)
    {
        u = _u; v = _v; ind = _ind;
    }
};
vector<TPair> fi, se;

void solve(vector<TPair> &cur)
{
    sort(cur.begin(), cur.end(), [](const TPair &a, const TPair &b) {
        return a.u > b.u;
    });
    int mx = 0;
    priority_queue<pair<int, int>> pq;
    for (TPair &u : cur)
    {
        for (; !pq.empty() && pq.top().first > u.u; pq.pop())
            if (f[pq.top().second] > f[mx])
                mx = pq.top().second;
        f[u.ind] = f[mx] + 1;
        tr[u.ind] = mx;
        pq.push({u.v, u.ind});
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> u >> v;
        if (u < v)
            fi.emplace_back(u, v, i);
        else
            se.emplace_back(-u, -v, i);
    }
    solve(fi); solve(se);
    int mx = 0;
    for (int i = 1; i <= n; i++)
        if (f[i] > f[mx])
            mx = i;
    cout << f[mx] << '\n';
    vector<int> ve;
    for (; mx != 0; mx = tr[mx])
        ve.push_back(mx);
    while (!ve.empty())
    {
        cout << ve.back() << " ";
        ve.pop_back();
    }
}