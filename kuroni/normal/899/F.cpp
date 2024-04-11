#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;

int n, m, l, r, bit[200005];
char s[200005], c;
vector<int> cur;
set<int> pos[256];
set<int>::iterator L, R;

void upd(int u, int v)
{
    for (; u <= n; u += u & -u)
        bit[u] += v;
}

int que(int u)
{
    int ret = 0;
    for (; u; u -= u & -u)
        ret += bit[u];
    return ret;
}

void BS(int &c)
{
    int l = 1, r = n, m;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (que(m) >= c)
            r = m - 1;
        else
            l = m + 1;
    }
    c = l;
}

int main()
{
    scanf("%d %d\n%s\n", &n, &m, s + 1);
    for (int i = 1; i <= n; i++)
    {
        upd(i, 1);
        pos[s[i]].insert(i);
    }
    while (m--)
    {
        scanf("%d %d %c\n", &l, &r, &c);
        BS(l);
        BS(r);
        L = pos[c].lower_bound(l);
        R = pos[c].upper_bound(r);
        for (set<int>::iterator it = L; it != R; it++)
            cur.push_back(*it);
        while (!cur.empty())
        {
            pos[c].erase(cur.back());
            upd(cur.back(), -1);
            cur.pop_back();
        }
    }
    for (int i = 1; i <= n; i++)
        if (que(i) > que(i - 1))
            printf("%c", s[i]);
}