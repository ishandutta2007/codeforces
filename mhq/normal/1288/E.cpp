#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 6 * (int)1e5 + 10;
int a[maxN];
int mn[maxN];
int mx[maxN];
struct Fenwick{
    vector < int > f;
    int n;

    Fenwick() {}

    Fenwick(int _n) {
        n = _n;
        f.resize(n + 2);
    }
    void upd(int v, int d) {
        while (v <= n) {
            f[v] += d;
            v = (v | (v - 1)) + 1;
        }
    }
    int get(int r) {
        int ans = 0;
        while (r > 0) {
            ans += f[r];
            r &= (r - 1);
        }
        return ans;
    }
    int get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
};
int lst[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        mn[i] = i;
        mx[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        mn[a[i]] = 1;
    }
    Fenwick f(n + m + 1);
    for (int i = 1; i <= n; i++) {
        lst[i] = n + 1 - i;
        f.upd(lst[i], 1);
    }
    for (int i = 1; i <= m; i++) {
        f.upd(lst[a[i]], -1);
        f.upd(i + n, 1);
        mx[a[i]] = max(mx[a[i]], f.get(lst[a[i]] + 1, i + n - 1) + 1);
        lst[a[i]] = i + n;
    }
    for (int i = 1; i <= n; i++) {
        mx[i] = max(mx[i], f.get(lst[i] + 1, n + m) + 1);
    }
    for (int i = 1; i <= n; i++) {
        cout << mn[i] << " " << mx[i] << '\n';
    }
    return 0;
}