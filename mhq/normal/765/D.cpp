#include <bits/stdc++.h>
using namespace std;
int n;
const int maxN = (int)1e5 + 10;
bool used[maxN];
int f[maxN];
int sz = 1;
int num[maxN];
int h[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
        if (!used[f[i]]) {
            used[f[i]] = true;
            cur++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (num[f[i]] == 0) {
            num[f[i]] = sz;
            h[sz] = f[i];
            sz++;
        }
        if (f[f[i]] != f[i]) {
            cout << -1;
            return 0;
        }
    }
    cout << cur << '\n';
    for (int i = 1; i <= n; i++) {
        cout << num[f[i]] << " ";
    }
    cout << '\n';
    for (int i = 1; i <= cur; i++) {
        cout << h[i] << " ";
    }
    return 0;
}