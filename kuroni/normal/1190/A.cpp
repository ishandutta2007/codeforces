#include <bits/stdc++.h>
using namespace std;

const int M = 100005;

int m, ans = 0;
long long n, k, a[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    int pt = 0;
    while (pt < m)
    {
        int lst = pt;
        long long cur = (a[pt] - lst) / k;
        while (pt < m && (a[pt] - lst) / k == cur)
            pt++;
        ans++;
    }
    cout << ans;
}