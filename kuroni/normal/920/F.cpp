#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;

const int N = 1E6 + 5;

set<int> pro;
vector<int> cur;
int n, q, d[N], a[N], t, x, y;
long long bit[N];

inline void upd(int u, int v)
{
    for (u; u <= n; u += u & -u)
        bit[u] += v;
}

inline long long que(int u)
{
    long long ret = 0;
    for (; u > 0; u -= u & -u)
        ret += bit[u];
    return ret;
}

void init()
{
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
            ++d[j];
}

int main()
{
    init();
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        if (a[i] != 1 && a[i] != 2)
            pro.insert(i);
        upd(i, a[i]);
    }
    while (q--)
    {
        scanf("%d%d%d", &t, &x, &y);
        if (t == 1)
        {
            for (set<int>::iterator it = pro.lower_bound(x), en = pro.upper_bound(y); it != en; it++)
            {
                int v = a[*it];
                a[*it] = d[v];
                upd(*it, d[v] - v);
                if (d[v] == 1 || d[v] == 2)
                    cur.push_back(*it);
            }
            while (!cur.empty())
            {
                pro.erase(cur.back());
                cur.pop_back();
            }
        }
        else
            printf("%I64d\n", que(y) - que(x - 1));
    }
}