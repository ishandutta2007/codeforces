#include <iostream>

using namespace std;

constexpr int N = 100000;
int a[N], _l, c[N], _r, cl, pl, am[N], n = N, prv[N], nxt[N], last[N];

int main()
{
    cin >> n, pl = n;
    for (int i = 0; i < n; ++i)
        cin >> a[i], --a[i];
    for (int i = n - 1; i > -1; --i)
        nxt[i] = last[a[i]] > i? last[a[i]]: n, last[a[i]] = i;
    for (int i = 0; i < n; ++i)
        prv[i] = last[a[i]] < i? last[a[i]]:-1, last[a[i]] = i;

    for (int k = 1; k <= n; ++k, pl = cl, cout << cl << ' ')
        for (cl = 0; c[cl - 1] < n; ++cl)
        {
            if (c[cl - 1] >= c[cl])
                am[cl] = 0,
                c[cl] = c[cl - 1];
            --c[cl];
            while (++c[cl] < n && am[cl] + (prv[c[cl]] < c[cl - 1]) <= k)
                am[cl    ] += c[cl] >= c[cl - 1] && prv[c[cl]] <  c[cl - 1],
                am[cl + 1] -= c[cl] <  c[cl + 1] && nxt[c[cl]] >= c[cl + 1];
        }
    return 0;
}