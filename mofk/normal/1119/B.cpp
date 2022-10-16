#include <bits/stdc++.h>

using namespace std;

int n, h;
int a[1005];
int b[1005];

bool check(int m) {
    for (int i = 1; i <= m; ++i) b[i] = a[i];
    sort(b + 1, b + m + 1, greater <int>());
    int s = 0;
    for (int i = 1; i <= m; i += 2) {
        s += b[i];
        if (s > h) return 0;
    }
    return 1;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> h;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int l = 1, r = n;
    while (l < r) {
        int m = l + r + 1 >> 1;
        if (check(m)) l = m;
        else r = m - 1;
    }
    cout << l << endl;
    return 0;
}