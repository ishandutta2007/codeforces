#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 100;

int f[N], n, m;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> f[i];
    sort(f + 1, f + m + 1);
    int ans = 1000000000;
    for (int i = 1; i + n - 1 <= m; i++)
        if (f[i + n - 1] - f[i] < ans)
            ans = f[i + n - 1] - f[i];
    cout << ans;
    return 0;
}