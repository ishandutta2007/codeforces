
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    base n; int k;
    cin >> n >> k;
    int m = k + 5;
    vector<base> y(m + 1);
    y[0] = 0;
    rep(i, 1, m + 1) {
        y[i] = y[i - 1] + base(i).pow(k);
    }
    vector<base> le(m + 2), ri(m + 2);
    le[0] = ri[m + 1] = 1;
    rep(i, 1, m + 1) {
        le[i] = le[i - 1] * (n - i);
    }
    for(int i = m; i >= 1; i--) {
        ri[i] = ri[i + 1] * (n - i);
    }
    vector<base> a(m + 1), b(m + 1);
    a[0] = 1;
    b[0] = 1;
    rep(i, 1, m + 1) {
        a[i] = a[i - 1] * i;
        b[i] = b[i - 1] * (-i);
    }
    base ans = 0;
    rep(i, 1, m + 1) {
        ans += y[i] * le[i - 1] * ri[i + 1] / (a[i - 1] * b[m - i]);
    }
    cout << ans << '\n';
}