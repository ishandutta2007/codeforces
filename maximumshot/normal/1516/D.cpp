#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int X = 1e5 + 5;

int pr[X];
int dv[X];

void precalc() {
    fill(pr, pr + X, 1);
    pr[0] = pr[1] = 0;
    for (int p = 2; p * p < X; p++) {
        if (!pr[p])
            continue;
        for (int x = p * p; x < X; x += p)
            pr[x] = 0;
    }
    for (int p = 2; p < X; p++) {
        if (!pr[p])
            continue;
        for (int x = p; x < X; x += p)
            dv[x] = p;
    }
}

int DIV(int x, int p) {
    while (x % p == 0)
        x /= p;
    return x;
}

vector<int> fast(int n, int q, vector<int> a, vector<pii> b) {
    vector<int> nxt(n + 1, n + 1), last(X, n + 1);
    for (int i = n; i >= 1; i--) {
        int mn = n + 1;
        for (int x = a[i]; x > 1;) {
            int p = dv[x];
            mn = min(mn, last[p]);
            last[p] = i;
            x = DIV(x, p);
        }
        nxt[i] = mn;
    }
    vector<int> R(n + 1);
    R[n] = n;
    for (int i = n - 1; i >= 1; i--) {
        R[i] = min(R[i + 1], nxt[i] - 1);
    }
    int LOG = 0;
    while ((1 << LOG) <= n) LOG++; LOG++;
    vector<vector<int>> link(LOG, vector<int>(n + 1, n + 1));
    for (int i = 1; i <= n; i++) {
        link[0][i] = R[i] + 1;
    }
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            int x = link[j - 1][i];
            if (x <= n) x = link[j - 1][x];
            link[j][i] = x;
        }
    }
    vector<int> res(q);
    for (int it = 0; it < q; it++) {
        auto [l, r] = b[it];
        int cnt = 0;
        for (int j = LOG - 1; j >= 0; j--) {
            int x = link[j][l];
            if (x > r) continue;
            cnt += 1 << j;
            l = x;
        }
        cnt++;
        res[it] = cnt;
    }
    return res;
}

void work() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<pii> b(q);
    for (int i = 0; i < q; i++)
        cin >> b[i].first >> b[i].second;
    vector<int> fs = fast(n, q, a, b);
    for (auto x : fs)
        cout << x << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    precalc();

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}