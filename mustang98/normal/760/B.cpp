#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 100111;

int main()
{
    int n, m, k, l = 0, r = 0, need, ans = 2;
    cin >> n >> m >> k;
    m -= n;
    if (m < 2)
    {
        cout << m + 1;
        return 0;
    }
    if (n == 1)
    {
        cout << 1 + m;
        return 0;
    }
    if (n == 2)
    {
        ans = 1 + m / 2;
        if (m % 2) ans++;
        cout << ans;
        return 0;
    }
    if (n == 3)
    {
        if (k == 2)
        {
            ans = 1 + m / 3;
            if (m % 3) ans++;
        }
        else
        {
            ans = 1 + m / 3;
            if (m) ans++;
        }
        cout << ans;
        return 0;
    }

    m--;
    while (true)
    {
        if (l < k - 1) l++;
        if (r < n - k) r++;
        need = l + r + 1;
        if(need <= m)
        {
            m -= need;
            ans++;
        }
        else
        {
            cout << ans;
            return 0;
        }
    }
}