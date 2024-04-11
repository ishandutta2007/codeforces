
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

const int M = 998244353;
using base = mod<M>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vi> g(n + 1);
    rep(i, 2, n + 1) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    vector<base> dp0(n + 1), dp1(n + 1);
    function<void(int)> dfs = [&](int x) {
        base prod0 = 1, prodsum = 1, sum = 0;
        for(int y : g[x]) {
            dfs(y);
            prod0 *= dp0[y];
            prodsum *= (dp0[y] + dp1[y]);
            sum += dp1[y] / dp0[y];
        }
        if(g[x].empty()) {
            dp0[x] = dp1[x] = 1;
        }else {
            dp0[x] = prodsum - sum * prod0;
            dp1[x] = prodsum - prod0;
        }
    };
    dfs(1);
    cout << dp0[1]() << '\n';
}