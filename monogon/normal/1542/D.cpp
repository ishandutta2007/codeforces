
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

const int M = 998'244'353;
using base = mod<M>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vi a(n + 1);
    rep(i, 1, n + 1) {
        char c; int x;
        cin >> c;
        if(c == '+') {
            cin >> x;
        }else x = -1;
        a[i] = x;
    }
    vector<vector<base>> ways(n + 1, vector<base>(n + 1, 0));
    base ans = 0;
    rep(i, 1, n + 1) {
        if(a[i] == -1) continue;
        ways[0][0] = 1;
        rep(j, 1, i) {
            rep(b, 0, n + 1) {
                ways[j][b] = ways[j - 1][b];
                if(a[j] == -1) {
                    if(b < n) ways[j][b] += ways[j - 1][b + 1];
                    if(b == 0) ways[j][b] += ways[j - 1][0];
                }else if(a[j] < a[i]) {
                    if(b > 0) ways[j][b] += ways[j - 1][b - 1];
                }else {
                    ways[j][b] += ways[j - 1][b];
                }
            }
        }
        rep(b, 0, n + 1) ways[i][b] = ways[i - 1][b];
        rep(j, i + 1, n + 1) {
            rep(b, 0, n + 1) {
                ways[j][b] = ways[j - 1][b];
                if(a[j] == -1) {
                    if(b < n) ways[j][b] += ways[j - 1][b + 1];
                }else if(a[j] <= a[i]) {
                    if(b > 0) ways[j][b] += ways[j - 1][b - 1];
                }else {
                    ways[j][b] += ways[j - 1][b];
                }
            }
        }
        rep(b, 0, n + 1) ans += ways[n][b] * a[i];
    }
    cout << ans << '\n';
}