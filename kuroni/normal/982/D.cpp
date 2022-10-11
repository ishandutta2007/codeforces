#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int N = 100005, INF = 1E9 + 7;

int n, a[N], ind[N], dsu[N];
bool chk[N];
multiset<int> se;

int trace(int u)
{
    return (dsu[u] < 0 ? u : dsu[u] = trace(dsu[u]));
}

void unity(int u, int v)
{
    if ((u = trace(u)) == (v = trace(v)))
        return;
    if (dsu[u] > dsu[v])
        swap(u, v);
    dsu[u] += dsu[v];
    dsu[v] = u;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ind[i] = i;
        dsu[i] = -1;
    }
    sort(ind + 1, ind + n + 1, [](const int &x, const int &y) { return a[x] < a[y]; });
    pair<int, int> ans = make_pair(0, -INF);
    for (int i = 1; i <= n;)
    {
        int val = a[ind[i]];
        while (a[ind[i]] == val)
        {
            int cur = 1, u = ind[i++];
            chk[u] = true;
            if (u > 1 && chk[u - 1])
            {
                int tr = trace(u - 1);
                cur += -dsu[tr];
                se.erase(se.find(-dsu[tr]));
                unity(u - 1, u);
            }
            if (u < n && chk[u + 1])
            {
                int tr = trace(u + 1);
                cur += -dsu[tr];
                se.erase(se.find(-dsu[tr]));
                unity(u + 1, u);
            }
            se.insert(cur);
        }
        if (*se.begin() == *se.rbegin())
            ans = max(ans, make_pair((int)se.size(), -val - 1));
    }
    cout << -ans.second;
}