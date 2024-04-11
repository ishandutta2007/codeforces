#include <bits/stdc++.h>

using namespace std;

int n;
int d[200005];
int mn[200005][2], c[200005];
int a[200005];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 2; i <= 200000; ++i) if (!d[i]) {
        for (int j = i; j <= 200000; j += i) d[j] = i;
    }
    for (int i = 2; i <= 200000; ++i) mn[i][0] = mn[i][1] = 10000000;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        map <int, int> mp;
        int x = a[i], y;
        while (x > 1) {
            int t = d[x];
            ++mp[t];
            x /= t;
        }
        for (auto z: mp) {
            x = z.first, y = z.second;
            ++c[x];
            if (mn[x][0] > y) mn[x][1] = mn[x][0], mn[x][0] = y;
            else if (mn[x][1] > y) mn[x][1] = y;
        }
    }
    long long ans = 1;
    for (int i = 2; i <= 200000; ++i) if (c[i] >= n - 1) {
        int f = 1 - n + c[i];
        for (int j = 1; j <= mn[i][f]; ++j) ans *= i;
    }
    cout << ans << endl;
    return 0;
}