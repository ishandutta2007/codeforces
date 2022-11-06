#include <bits/stdc++.h>

using namespace std;

long long n, m, k;

bool check(long long x)
{
    long long a1;
    if (x - k + 1 > 0)
        a1 = (2*x - k)*(k - 1) / 2;
    else
        a1 = k - x + (x - 1)* x / 2;
    long long a2 = x;
    long long a3;
    if (x - n + k > 0)
        a3 = (2*x - n + k - 1)*(n - k) / 2;
    else
        a3 = n - k - x + 1 + (x-1)*x / 2;
   // cout << x << ' ' <<k << ' ' << x-k+1 << ' ' << a1 << ' ' << a2 << ' ' << a3 << endl;
    if (a1 + a2 + a3 <= m)
        return true;
    return false;
}

int main()
{
    cin >> n >> m >> k;
    int l = 0;
    int r = 1000000001;
    while (l < r - 1)
    {
        long long m = (r + l) / 2;
        if (check(m))
            l = m;
        else
            r = m;
    }
    cout << l;
    return 0;
}