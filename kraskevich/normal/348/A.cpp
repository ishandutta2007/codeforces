#include <bits/stdc++.h>

using namespace std;

const int N = 100 * 1000 + 10;

long long a[N];
int n;

bool good(long long x)
{
    long long h = 0;
    for (int i = 0; i < n; i++)
    {
        h += x - a[i];
        if (h > x)
            return true;
    }
    return h >= x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    #if defined DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    long long l = a[n - 1];
    long long r = (long long)1e14;
    while (l < r)
    {
        long long m = (l + r) / 2;
        if (good(m))
            r = m;
        else
            l = m + 1;
    }
    cout << l;

    return 0;
}