#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

int a[200010];
vector <pair<int, int>> e[200010];
vector <int> f[200010];
int p[200010], nx[200010], mx[200010];
long long ans, s;

int qp(int n, int m) {
    long long k = 1, t = n;
    while(m) {
        if (m & 1) {
            k = k * t % MOD;
        }
        t = t * t % MOD;
        m >>= 1;
    }
    return k;
}

void init(int n) {
    for(int k = 2; k <= n; k++) {
        if (!p[k]) {
            p[++p[0]] = k;
        }
        for(int i = 1; i <= p[0] && i <= n / k; i++) {
            p[k * i] = 1;
        }
    }
    for(int k = 2; k <= n; k++) {
        for(int i = 1; i <= p[0]; i++) {
            if (k % p[i] == 0) {
                nx[k] = p[i];
                break;
            }
        }
    }
}

void dfs(int k) {
    a[k] = 1;
    for(int i = 0; i < e[k].size(); i++) {
        if (a[f[k][i]] == 0) {
            int q = e[k][i].second;
            while (q > 1) {
                p[nx[q]]--;
                q /= nx[q];
            }
            q = e[k][i].first;
            while (q > 1) {
                p[nx[q]]++;
                mx[nx[q]] = max(mx[nx[q]], p[nx[q]]);
                q /= nx[q];
            }
            dfs(f[k][i]);
            q = e[k][i].second;
            while (q > 1) {
                p[nx[q]]++;
                q /= nx[q];
            }
            q = e[k][i].first;
            while (q > 1) {
                p[nx[q]]--;
                q /= nx[q];
            }
        }
    }
}

void dfs2(int k) {
    a[k] = 1;
    ans += s;
    ans %= MOD;
    for(int i = 0; i < e[k].size(); i++) {
        if (a[f[k][i]] == 0) {
            s = s * e[k][i].second % MOD;
            s = s * qp(e[k][i].first, MOD - 2) % MOD;
            dfs2(f[k][i]);
            s = s * e[k][i].first % MOD;
            s = s * qp(e[k][i].second, MOD - 2) % MOD;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, t;
    init(2e5);
    cin >> t;
    while (t--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            e[i].clear();
            f[i].clear();
            a[i] = 0;
            p[i] = 0;
            mx[i] = 0;
        }
        int k, l, x, y;
        for(int i = 1; i < n; i++) {
            cin >> k >> l >> x >> y;
            int q = __gcd(x, y);
            x /= q;
            y /= q;
            e[k].push_back(make_pair(x, y));
            e[l].push_back(make_pair(y, x));
            f[k].push_back(l);
            f[l].push_back(k);
        }
        dfs(1);
        s = 1;
        for(int i = 1; i <= n; i++) {
            a[i] = 0;
            if (mx[i]) {
                s = s * qp(i, mx[i]) % MOD;
            }
        }
        ans = 0;
        dfs2(1);
        cout << ans << endl;
    }
}