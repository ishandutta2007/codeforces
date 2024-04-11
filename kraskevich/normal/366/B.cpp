#include <bits/stdc++.h>

using namespace std;

const int INF = 1000 * 1000 * 1000;

int main()
{
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(2 * n);
    int res = INF;
    int id = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int start = 0; start < k; start++)
    {
        int fin = start + n;
        int cost = 0;
        int cur = start;
        while (cur < fin)
        {
            cost += a[cur];
            cur += k;
        }
        if (cost < res)
            id = start + 1;
        res = min(res, cost);
    }
    cout << id;

    return 0;
}