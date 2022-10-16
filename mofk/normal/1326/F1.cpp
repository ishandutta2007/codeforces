#include <bits/stdc++.h>

using namespace std;

const int maxn = 14;
int n;
vector <int> pc[1 << maxn];
long long a[maxn][maxn];
long long b[maxn][maxn];
long long f[1 << maxn][maxn];
long long ones[maxn];
long long ans[1 << maxn];

long long dot(long long *x, long long *y) {
    long long ret = 0;
    for (int i = 0; i < n; ++i) ret += x[i] * y[i];
    return ret;
}

vector <int> gen(int n) {
    if (n == 1) return {0, 1};
    vector <int> v = gen(n - 1);
    vector <int> u = v;
    for (int i = v.size() - 1; i >= 0; --i) u.push_back(v[i] + (1 << n - 1));
    return u;
}

int flips(int x) {
    int r = 0;
    for (int i = 0; i < n - 1; ++i) if (x >> i & 1)
        r += (1 << n - 2 - i);
    return r;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) ones[i] = 1;
    for (int i = 1; i < (1 << n); ++i) for (int j = 0; j < n; ++j)
        if (i >> j & 1) pc[i].push_back(j);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) a[i][j] = (s[j] == '0');
        a[i][i] = 0;
        for (int j = 0; j < n; ++j) b[i][j] = (s[j] == '1');
    }
    for (int i = 0; i < n; ++i) f[1 << i][i] = 1;
    for (int i = 1; i < (1 << n); ++i) if (pc[i].size() > 1) {
        for (auto v: pc[i]) f[i][v] = dot(f[i - (1 << v)], a[v]);
    }
    vector <int> ord = gen(n - 1);
    for (auto &x: ord) x = flips(x);
    ans[ord[0]] = dot(f[(1 << n) - 1], ones);
    for (int i = 1; i < ord.size(); ++i) {
        int j = ord[i] ^ ord[i - 1];
        j = log2(j);
        for (int m = 1; m < (1 << n); ++m) if (pc[m].size() > j + 1) {
            int id = ord[i] >> (pc[m].size() - 2) & 1;
            for (auto v: pc[m]) f[m][v] = dot(f[m - (1 << v)], id ? b[v] : a[v]);
        }
        ans[ord[i]] = dot(f[(1 << n) - 1], ones);
    }
    for (int i = 0; i < (1 << n - 1); ++i) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}