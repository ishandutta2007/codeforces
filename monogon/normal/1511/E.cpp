
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

const int M = 998244353;
using base = mod<M>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> s(n + 1);
    s[0].assign(m + 1, '*');
    rep(i, 1, n + 1) {
        cin >> s[i];
        s[i].insert(s[i].begin(), '*');
    }
    vector<vi> up(n + 1, vi(m + 1, 0)), le(n + 1, vi(m + 1, 0));
    rep(i, 1, n + 1) rep(j, 1, m + 1) {
        if(s[i][j] == '*') {
            up[i][j] = le[i][j] = 0;
        }else {
            up[i][j] = 1 + up[i - 1][j];
            le[i][j] = 1 + le[i][j - 1];
        }
    }

    int N = max(n, m) + 5;
    vector<base> dp(N);
    base inv2 = base(2).inv();
    dp[2] = inv2 * inv2;
    rep(i, 3, N) dp[i] = inv2 * inv2 * (inv2 + dp[i - 2]);
    base ans = 0;
    int w = 0;
    rep(i, 1, n + 1) rep(j, 1, m + 1) {
        ans += dp[up[i][j]] + dp[le[i][j]];
        w += (s[i][j] == 'o');
    }
    ans *= base(2).pow(w);
    cout << ans << '\n';
}