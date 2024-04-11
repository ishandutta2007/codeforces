#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e5 + 100;
int x[maxN], y[maxN], z[maxN];
bool used[maxN];
int n;
int val(int a, int b) {
    return abs(x[a] - x[b]) + abs(y[a] - y[b]) + abs(z[a] - z[b]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> z[i];
    }
    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;
        int best = -1;
        for (int j = i + 1; j <= n; j++) {
            if (used[j]) continue;
            if (best == -1 || (val(i, j) < val(i, best))) {
                best = j;
            }
        }
        cout << i << " " << best << '\n';
        used[i] = used[best] = true;
    }
    return 0;
}