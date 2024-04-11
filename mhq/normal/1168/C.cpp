#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 3 * (int)1e5 + 100;
const int LOG = 20;
int nxt[maxN][LOG];
int a[maxN];
int n, q;
int val[LOG];
bool used[LOG];
void solve(int x, int y) {
    for (int j = 0; j < LOG; j++) {
        val[j] = n + 1;
        used[j] = false;
    }
    for (int i = 0; i < LOG; i++) {
        if (a[x] & (1 << i)) val[i] = x;
    }
    for (int i = 0; i < LOG; i++) {
        int v = -1;
        for (int j = 0; j < LOG; j++) {
            if (!used[j] && (v == -1 || val[j] < val[v])) v = j;
        }
        if (val[v] == n + 1) break;
        used[v] = true;
        for (int j = 0; j < LOG; j++) {
            int to = nxt[val[v]][j];
            if (val[j] > to) {
                val[j] = to;
            }
        }
    }
    for (int i = 0; i < LOG; i++) {
        if ((a[y] & (1 << i)) && val[i] <= y) {
            cout << "Shi" << '\n';
            return;
        }
    }
    cout << "Fou" << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int lg = 0; lg < LOG; lg++) {
        for (int j = 1; j <= n; j++) nxt[j][lg] = n + 1;
        for (int cur_bit = 0; cur_bit < LOG; cur_bit++) {
            int mn = n + 1;
            for (int j = n; j >= 1; j--) {
                if (j < n && ((a[j + 1] & (1 << lg)) && ((a[j + 1] & (1 << cur_bit))))) {
                    mn = j + 1;
                }
                if (a[j] & (1 << cur_bit)) nxt[j][lg] = min(nxt[j][lg], mn);
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        solve(x, y);
    }
    return 0;
}