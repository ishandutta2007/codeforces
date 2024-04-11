#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 4 * (int)1e6 + 100;
int f[maxN];
bool ok[maxN];
int sz[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    if (n == 2) {
        cout << 1;
        return 0;
    }
    int t = 1;
    while (2 * t + 1 <= n) t = 2 * t + 1;
    for (int i = 1; i <= t; i++) {
        ok[i] = true;
    }
    int p = n;
    while (!ok[p]) p--;
    int cnt = p;
    for (int i = p; i >= 1; i--) {
        if (i == 1) break;
        if (i % 2 == 0) {
            if (sz[2 * i + 1] % 2 == 1) {
                cnt++;
                sz[2 * i + 1]++;
            }
        }
        else {
            if (sz[2 * i] % 2 == 0) {
                cnt++;
                sz[2 * i]++;
            }
        }
        sz[i] = sz[2 * i] + sz[2 * i + 1] + 1;
    }
    if (cnt == n || cnt + 1 == n) {
        cout << 1;
        return 0;
    }
    else {
        cout << 0;
        return 0;
    }
    return 0;
}