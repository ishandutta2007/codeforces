#include <bits/stdc++.h>

typedef long long ll;

const int INF = 2e9;
const int mod = 1e9 + 7;

using namespace std;

ll mn[17][150150], mx[17][150150];
ll sb[150150];

int x[200200];

ll a[200200];

int L[200200];

ll T[1 << 19];

ll askmn(int l, int r) {
    return min(mn[L[r - l]][l], mn[L[r - l]][r - (1 << L[r - l])]);
}

ll askmx(int l, int r) {
    return max(mx[L[r - l]][l], mx[L[r - l]][r - (1 << L[r - l])]);
}

void build(int v, int l, int r) {
    if(l + 1 == r) {
        T[v] = max(0ll, a[l]);
        return;
    }
    int m = (l + r) / 2;
    build(2 * v, l, m);
    build(2 * v + 1, m, r);
    T[v] = max(T[2 * v + 1], T[2 * v]);
    T[v] = max(T[v], askmx(m, r) - askmn(l - 1, m));
}

ll ask(int v, int l, int r, int l1, int r1) {
    if(l == l1 && r == r1)
        return T[v];
    int m = (l + r) / 2;
    if(r1 <= m)
        return ask(2 * v, l, m, l1, r1);
    if(l1 >= m)
        return ask(2 * v + 1, m, r, l1, r1);
    ll ans = max(ask(2 * v, l, m, l1, m), ask(2 * v + 1, m, r, m, r1));
    ans = max(ans, askmx(m, r1) - askmn(l1 - 1, m));
    return ans;
}

void solve() {
    int n, m, c;
    cin >> n >> m >> c;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
        a[i] = 0;
    }
    for(int i = 0; i < n - 1; ++i) {
        int p;
        scanf("%d", &p);
        a[i + 1] -= p * c;
        a[i + 1] += (x[i + 1] - x[i]) * 50ll;
    }
    sb[0] = 0;
    for(int i = 1; i < n; ++i)
        sb[i] = sb[i - 1] + a[i];
    for(int i = 0; i < n; ++i)
        mn[0][i] = mx[0][i] = sb[i];
    for(int i = 1; i < 17; ++i) {
        for(int j = 0; j < n; ++j) {
            mn[i][j] = mn[i - 1][j];
            mx[i][j] = mx[i - 1][j];
            if(j + (1 << (i - 1)) < n) {
                mn[i][j] = min(mn[i][j], mn[i - 1][j + (1 << (i - 1))]);
                mx[i][j] = max(mx[i][j], mx[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    L[0] = -1;
    for(int i = 1; i <= n; ++i)
        L[i] = L[i / 2] + 1;
    ll ans = 0;
    build(1, 1, n);
    for(int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        ans += ask(1, 1, n, l, r);
    }
    printf("%.10lf", (double)ans / 100.0);
}

int main() {
    solve();
    return 0;
}