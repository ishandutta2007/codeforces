#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 300005;

int n, m;
long long u, cur = 0, x[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
        if (i > 1)
            cur = __gcd(cur, x[i] - x[i - 1]);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> u;
        if (cur % u == 0)
        {
            cout << "YES\n" << x[1] << " " << i;
            return 0;
        }
    }
    cout << "NO";
    return 0;
}