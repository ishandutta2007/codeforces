
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
    ll n;
    int k;
    cin >> n >> k;
    const int N = 2 * k + 5, K = k + 5;
    vector<vector<base>> /*choose(N, vector<base>(K)), */c(N, vector<base>(K));
    // rep(i, 0, N) rep(j, 0, K) {
    //     if(j == 0) choose[i][j] = 1;
    //     else if(i == 0) choose[i][j] = 0;
    //     else choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
    // }
    vector<base> ans(N);
    base ch = 1;
    rep(i, 0, N) {
        rep(j, 0, K) {
            if(i == 0) {
                if(j == 0) c[i][j] = 1;
                else c[i][j] = 0;
            }else if(j == 0) {
                c[i][j] = 0;
            }else {
                base prod = 1;
                rep(l, 2, i + 1) {
                    prod *= (i - l + 1);
                    c[i][j] += prod * c[i - l][j - 1];
                }
            }
            if(i >= j && i <= n) ans[i - j] += ch * c[i][j];
        }
        ch *= (n - i);
        ch /= i + 1;
    }
    rep(i, 1, k + 1) {
        if(i > 1) ans[i] += ans[i - 2];
        cout << ans[i] << ' ';
    }
    cout << '\n';
}