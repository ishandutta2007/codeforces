#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 1E6 + 5;

int t, x, p, k;
vector<int> pr[MAX];

void init()
{
    for (int i = 2; i < MAX; i++)
        if (pr[i].empty())
            for (int j = i; j < MAX; j += i)
                pr[j].push_back(i);
}

int num(int a, int p)
{
    int n = pr[p].size(), ret = 0;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int div = 1;
        for (int i = 0; i < n; i++)
            if (mask >> i & 1)
                div *= pr[p][i];
        if (__builtin_popcount(mask) & 1)
            ret -= a / div;
        else
            ret += a / div;
    }
    return ret;
}

int solve(int x, int p, int k)
{
    int st = num(x, p), l = x + 1, r = 1E9, m;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (num(m, p) - st >= k)
            r = m - 1;
        else l = m + 1;
    }
    return l;
}

int main()
{
    init();
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &x, &p, &k);
        printf("%d\n", solve(x, p, k));
    }
}