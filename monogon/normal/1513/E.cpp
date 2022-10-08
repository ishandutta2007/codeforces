
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
    int n;
    cin >> n;
    map<int, int> ma;
    ll sum = 0;
    rep(i, 0, n) {
        int a; cin >> a;
        ma[a]++;
        sum += a;
    }
    if(sum % n != 0) {
        cout << 0 << '\n';
        return 0;
    }
    ll x = sum / n;
    int N = 2 * n + 5;
    vector<base> fact(N, 1);
    rep(i, 1, N) fact[i] = fact[i - 1] * i;
    vi va, vb, vc;
    int a = 0, b = 0, c = 0;
    for(auto &pa : ma) {
        int val, occ;
        tie(val, occ) = pa;
        if(val < x) {
            a += occ;
            va.push_back(occ);
        }else if(val == x) {
            b += occ;
            vb.push_back(occ);
        }else {
            c += occ;
            vc.push_back(occ);
        }
    }
    if(a == 0) {
        cout << 1 << '\n';
        return 0;
    }
    base ans = fact[n] / (fact[b] * fact[n - b]);
    ans *= fact[a] * fact[c];
    for(int v : va) ans /= fact[v];
    for(int v : vc) ans /= fact[v];
    if(a == 1) ans *= c + 1;
    else if(c == 1) ans *= a + 1;
    else ans *= 2;
    cout << ans << '\n';
}