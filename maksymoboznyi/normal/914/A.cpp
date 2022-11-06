#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e6+6;

signed main()
{
    int n, m = -1000000000, x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (x < 0 || sqrt(x) != trunc(sqrt(x)))
            m = max(m, x);
    }
    cout << m;
    return 0;
}