#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e6 + 100;
const int LG = 21;
int val[(1 << LG) + 2];
int a[maxN];
int n;
void add(int v, int bit, bool need_to_add) {
    if (bit < 0) return;
    if (need_to_add && val[v] >= 2) return;
    if (need_to_add) val[v]++;
    if (v & (1 << bit)) {
        add(v ^ (1 << bit), bit, true);
    }
    add(v, bit - 1, false);
}
int go(int need) {
    int msk = 0;
    for (int i = LG - 1; i >= 0; i--) {
        if (!(need & (1 << i))) continue;
        if (val[msk | (1 << i)] >= 2) {
            msk |= (1 << i);
        }
    }
    return msk;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    const int all = (1 << LG) - 1;
    for (int i = n; i >= 1; i--) {
        int need = all ^ a[i];
        if (i + 2 <= n) {
            int p = a[i] | go(need);
            ans = max(ans, p);
        }
        add(a[i], LG - 1, true);
    }
    cout << ans;

    return 0;
}