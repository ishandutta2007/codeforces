#include <algorithm>
#include <iostream>
#include <vector>
#include <random>
#include <cstring>
#include <set>

using namespace std;

vector<int> v;
set<pair<int, int>> s;
int n, k, a[int(1e6)], ans;

bool tr(int x)
{
    bool res = 1;
    if (x <= 100)
        for (int i = 0; i < n && res; ++i)
            res &= (a[i] % x) <= k;
    else
        for (int i = 0; i < n && res; ++i)
            res &= (a[i] % x) <= k, i = upper_bound(a + i, a + n, a[i] - (a[i] % x) + k) - a - 1;
    return res;
}

char pos[int(1e6 + 1)];

int main()
{
    memset(pos, 1, sizeof(pos));
    cin.tie(0), ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    ans = min(k + 1, a[0]);
    for (int i = 1; i <= a[0]; ++i) if (i <= a[0])
    {
        if (!pos[i] || i <= ans)
            continue;
        bool res = tr(i);
        if (res)
            ans = max(ans, i);
        if (!res)
            for (int j = i; j <= a[0]; j += i)
                pos[j] = 0;
    }
    cout << ans;
    return 0;
}