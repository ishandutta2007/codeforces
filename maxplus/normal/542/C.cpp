#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int64_t n, pre, per = 1, f[200], m[200];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        (cin >> f[i]), --f[i];
    for (int se = 0; se < n; ++se)
    {
        int64_t cur = se, l = 0;
        memset(m, 255, sizeof(m));
        m[cur] = l;
        while (m[cur = f[cur]] == -1) m[cur] = ++l;
        pre = max(pre, m[cur]);
        per = per / __gcd(per, l - m[cur] + 1) * (l - m[cur] + 1);
    }
    cout << max(pre + per - 1 - (pre - 1) % per, 1ll);
    return 0;
}