#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, ind[N], a[N], ans[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ind[i] = i;
    }
    sort(ind, ind + n, [&](const int &u, const int &v) {
        return a[u] > a[v];
    });
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[ind[i]]; j++) {
            ans[(i + j) % (n + 1)][ind[i]] = 1;
        }
    }
    cout << n + 1 << '\n';
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}