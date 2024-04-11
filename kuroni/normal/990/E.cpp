#include <bits/stdc++.h>
using namespace std;

const int N = 1E6 + 5;
const long long INF = 1E12 + 7;

int n, m, k, u, a[N];
long long ans = INF;

int solve(int u) {
    int st = 0, cnt = 0;
    while (true) {
        cnt++;
        if (st + u >= n) {
            return cnt;
        } else if (a[st + u] == st) {
            return -1;
        } else {
            st = a[st + u];
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    while (m--) {
        cin >> u;
        if (u == 0) {
            return cout << -1, 0;
        }
        a[u] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            a[i] = a[i - 1];
        } else {
            a[i] = i;
        }
    }
    for (int i = 1; i <= k; i++) {
        cin >> u;
        int cnt = solve(i);
        if (cnt > -1) {
            ans = min(ans, 1LL * cnt * u);
        }
    }
    cout << (ans == INF ? -1 : ans);
}