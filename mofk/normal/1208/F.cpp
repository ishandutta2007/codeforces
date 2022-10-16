#include <bits/stdc++.h>

using namespace std;

int n, m = 1 << 21;
int a[1000006];
int f[1<<21][2];

void add(int x, int y) {
    if (y == f[x][0] || y == f[x][1]) return;
    if (f[x][0] < y) f[x][1] = f[x][0], f[x][0] = y;
    else if (f[x][1] < y) f[x][1] = y;
}

bool can(int tar) {
    for (int i = 1; i <= n; ++i) {
        int ok = tar & (m - 1 - a[i]);
        if (f[ok][1] > i) return 1;
    }
    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = n; i >= 1; --i) {
        if (f[a[i]][0]) f[a[i]][1] = i;
        else f[a[i]][0] = i;
    }
    for (int i = m - 1; i >= 0; --i) {
        for (int j = 0; j < 21; ++j) if (!(i >> j & 1)) {
            int k = i | (1 << j);
            add(i, f[k][0]);
            add(i, f[k][1]);
        }
    }
    int ans = 0;
    for (int j = 20; j >= 0; --j) if (can(ans | (1 << j))) ans |= 1 << j;
    cout << ans << endl;
    return 0;
}