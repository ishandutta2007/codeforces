#include <bits/stdc++.h>

using namespace std;
//#pragma GCC optimize("O3")

typedef long long ll;
typedef long double ld;
int n;
const int maxN = 2e5 + 10;
int k;
int val1[maxN];
int val2[maxN];
const int INF = (int)1e9;
int fenw[3 * maxN];
void upd(int v, int by) {
    v += n + 2;
    assert(v > 0);
    while (v <= 3 * n + 6) {
        fenw[v] = min(fenw[v], by);
        v = (v | (v - 1)) + 1;
    }
}
int get(int r) {
    int ans = INF;
    r += (n + 2);
    while (r > 0) {
        ans = min(ans, fenw[r]);
        r &= (r - 1);
    }
    return ans;
}
int a[maxN];
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        if (a[1] == k) cout << "yes\n";
        else cout << "no\n";
        return;
    }
    bool has = false;
    for (int i = 1; i <= n; i++) {
        if (a[i] == k) has = true;
    }
    if (!has) {
        cout << "no\n";
        return;
    }
    for (int i = 1; i + 1 <= n; i++) {
        if (a[i] >= k && a[i + 1] >= k) {
            cout << "yes\n";
            return ;
        }
    }
    for (int i = 1; i + 2 <= n; i++) {
        if (a[i] >= k && a[i + 2] >= k) {
            cout << "yes\n";
            return;
        }
    }
    cout << "no\n";
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }

    return 0;
}