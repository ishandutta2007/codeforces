#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n, a[N], cur = 0, used[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    while (1) {
        int cs = cur;
        for (int i = 1; i <= n; i++)
            if (!used[i] && a[i] <= cur)
                cur++, used[i] = 1;
        if (cur == n) {
            cout << ans;
            return 0;
        }
        ans++;
        for (int i = n; i > 0; i--)
            if (!used[i] && a[i] <= cur)
                cur++, used[i] = 1;
        if (cur == n) {
            cout << ans;
            return 0;
        }
        ans++;
    }
    return 0;
}