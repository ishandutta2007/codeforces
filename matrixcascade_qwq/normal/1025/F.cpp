#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
const double PI = acos(-1.0);
int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}
int x[3030], y[3030];
vector<double> v;
signed main()
{
    int ans = 0;
    n = read();
    for (int i = 1; i <= n; ++i)
    {
        x[i] = read(), y[i] = read();
    }
    for (int i = 1; i <= n; ++i)
    {
        v.clear();
        for (int j = 1; j <= n; ++j)
        {
            if (i != j)
            {
                v.push_back(atan2(y[j] - y[i], x[j] - x[i]));
            }
        }
        sort(v.begin(), v.end());
        for (int j = 0, nw = 0; j < v.size() && v[j] <= 0; ++j)
        {
            while (nw < v.size() && v[nw] - v[j] < PI)
            {
                ++nw;
            }
            int a = nw - j - 1, b = v.size() - a - 1;
            ans += a * (a - 1) / 2 * b * (b - 1) / 2;
        }
    }
    cout << ans << endl;
}