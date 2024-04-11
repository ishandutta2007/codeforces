
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<int m>
struct mod {
    long long x;
    mod() : x(0) {}
    mod(long long xx) : x(xx) {
        if(abs(x) >= m) x %= m;
        if(x < 0) x += m;
    }
    mod operator+(const mod &a) const {
        mod n;
        n.x = x + a.x;
        if(n.x >= m) n.x -= m;
        return n;
    }
    mod operator-(const mod &a) const {
        mod n;
        n.x = x - a.x;
        if(n.x < 0) n.x += m;
        return n;
    }
    mod operator*(const mod &a) const {
        return x * a.x;
    }
    mod operator+=(const mod &a) {
        x += a.x;
        if(x >= m) x -= m;
        return *this;
    }
    mod operator-=(const mod &a) {
        x -= a.x;
        if(x < 0) x += m;
        return *this;
    }
    mod operator*=(const mod &a) {
        x = (x * a.x) % m;
        return *this;
    }
    mod pow(long long b) const {
        mod ans = 1;
        mod a = *this;
        while(b > 0) {
            if(b & 1) ans *= a;
            a *= a;
            b /= 2;
        }
        return ans;
    }
    mod inv() const {
        return pow(m - 2);
    }
    mod operator/(const mod &a) const {
        return (*this) * a.inv();
    }
    mod operator/=(const mod &a) {
        return (*this) *= a.inv();
    }
    bool operator==(const mod &o) const {
        return x == o.x;
    }
    bool operator!=(const mod &o) const {
        return x != o.x;
    }
    long long operator()() const {
        return x;
    }
};

template<int m>
istream &operator>>(istream &is, mod<m> &n) {
    long long x;
    is >> x;
    n = x;
    return is;
}

template<int m>
ostream &operator<<(ostream &os, const mod<m> &n) {
    return os << n();
}
const int M = 1e9 + 7;
using base = mod<M>;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vi> g(n + 1);
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vi dist(n + 1, 0), par(n + 1, 0);
    auto dfs = [&](auto dfs, int x, int p) -> void {
        for(int y : g[x]) {
            if(y != p) {
                dist[y] = 1 + dist[x];
                if(par[x] == 0) par[y] = y;
                else par[y] = par[x];
                dfs(dfs, y, x);
            }
        }
    };
    vector<vi> hist(n + 1, vi(n + 1, 0));
    vector<base> fact(n + 1, 1);
    rep(i, 1, n + 1) fact[i] = fact[i - 1] * i;
    base ans = 0;
    if(k == 2) {
        ans = 1LL * n * (n - 1) / 2;
        cout << ans << '\n';
        return;
    }
    rep(r, 1, n + 1) {
        fill(all(dist), 0);
        fill(all(par), 0);
        dfs(dfs, r, r);
        rep(i, 0, n + 1) rep(j, 1, n + 1) hist[i][j] = 0;
        rep(i, 1, n + 1) hist[dist[i]][par[i]]++;
        vector<base> hmm(k + 1, 0);
        rep(d, 0, n + 1) {
            fill(all(hmm), 0);
            hmm[0] = 1;
            rep(i, 1, n + 1) {
                if(hist[d][i] > 0) {
                    for(int j = k; j >= 1; j--) {
                        hmm[j] += hmm[j - 1] * hist[d][i];
                    }
                }
            }
            ans += hmm[k];
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}