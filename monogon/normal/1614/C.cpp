
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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> ve(n + 2);
    rep(i, 0, m) {
        int l, r; ll x;
        cin >> l >> r >> x;
        ve[l].push_back({1, x});
        ve[r + 1].push_back({-1, x});
    }

    vi cnt(31, 0);
    vector<ll> a(n + 1, 0);
    rep(i, 1, n + 1) {
        for(auto &pa : ve[i]) {
            rep(j, 0, 31) {
                if(~pa.second >> j & 1) {
                    cnt[j] += pa.first;
                }
            }
        }
        a[i] = (1LL << 30) - 1;
        rep(j, 0, 31) {
            if(cnt[j] > 0) {
                a[i] &= ~(1ll << j);
            }
        }
    }
    vector<base> pow2(n + 2);
    pow2[0] = 1;
    rep(i, 1, n + 2) {
        pow2[i] = pow2[i - 1] * 2;
    }
    base ans = 0;
    rep(j, 0, 31) {
        int cnt = 0;
        rep(i, 1, n + 1) {
            if(a[i] >> j & 1) {
                cnt++;
            }
        }
        // cnt 1's and (n - cnt) 0's
        // (cnt choose odd) = 2^(cnt - 1)
        if(cnt > 0) {
            ans += base(1ll << j) * pow2[n - 1];
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