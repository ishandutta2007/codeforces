#include <iostream>
#include <vector>
#include <map>
#include <set>
#define pb push_back

using namespace std;

const int N = 200000;
map<int, int> m[N];
set<int> nei[N];
int n, forks, a, b;

int rise(int v, int pv = -1, int d = 0)
{
    if (nei[v].size() > 2)
        if (m[v].count(d))
            return
            nei[v].erase(m[v][d]),
            m[v].erase(d),
            forks -= nei[v].size() <= 2,
                    1;
        else
            return m[v].insert({d, pv}), 0;
    for (auto i: nei[v])
        if (i != pv)
            return rise(i, v, d + 1);
    return d;
}

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; ++i)
        cin >> a >> b, nei[--a].insert(--b), nei[b].insert(a);
    for (int i = 0; i < n; ++i)
        forks += nei[i].size() > 2;
    for (int i = 0; i < n; ++i)
        if (nei[i].size() == 1)
            while (1)
                if (forks)
                    if (!rise(i))
                        break;
                else;else
                    return n = rise(i), cout << (n >> __builtin_ctz(n)), 0;
    cout << -1;
    return 0;
}