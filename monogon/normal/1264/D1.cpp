
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

const int N = 2005;
base dp[N][N];
base way[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    way[n] = 1;
    for(int i = n - 1; i >= 0; i--) {
        way[i] = way[i + 1];
        if(s[i] == '?') way[i] *= 2;
    }
    auto can = [&](char a, char b) {
        return a == b || a == '?';
    };
    rep(len, 0, n + 1) {
        for(int i = 0; i + len <= n; i++) {
            if(len <= 1) {
                dp[len][i] = 0;
            }else {
                if(can(s[i], '(') && can(s[i + len - 1], ')')) {
                    dp[len][i] += way[i + 1] / way[i + len - 1] + dp[len - 2][i + 1];
                }
                if(can(s[i], ')')) {
                    dp[len][i] += dp[len - 1][i + 1];
                }
                if(can(s[i + len - 1], '(')) {
                    dp[len][i] += dp[len - 1][i];
                }
                if(can(s[i], ')') && can(s[i + len - 1], '(')) {
                    dp[len][i] -= dp[len - 2][i + 1];
                }
            }
        }
    }
    cout << dp[n][0] << '\n';
}