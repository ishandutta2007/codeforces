#include <bits/stdc++.h>

using namespace std;

const int N = 100 * 1000 + 10;

long long h[N];
long long p[N];
int n, m;

long long ABS(long long a)
{
    return a > 0 ? a : -a;
}

bool check(long long t)
{
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        if (l == m)
            break;
        if (ABS(h[i] - p[l]) > t)
            continue;
        int lo = l;
        int hi = m - 1;
        while (lo < hi)
        {
            int r = (lo + hi + 1) / 2;
            long long cur = 0;
            if (p[l] <= h[i] && p[r] <= h[i])
                cur = h[i] - p[l];
            if (p[r] >= h[i] && p[l] >= h[i])
                cur = p[r] - h[i];
            if (p[r] > h[i] && p[l] < h[i])
                cur = p[r] - p[l] + min(p[r] - h[i], h[i] - p[l]);
            if (cur <= t)
                lo = r;
            else
                hi = r - 1;
        }
        l = lo + 1;
    }
    return l == m;
}

int main()
{
    ios_base::sync_with_stdio(0);
    #if defined DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < m; i++)
        cin >> p[i];

    long long l = 0;
    long long r = (long long)1e11;
    while (l < r)
    {
        long long mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l;


    return 0;
}