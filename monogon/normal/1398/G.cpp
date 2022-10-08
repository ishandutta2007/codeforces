
#define _USE_MATH_DEFINES
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
    mod operator/(const mod &a) {
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

template<typename T>
T root(int n, bool inv = false);

using ftype = double;
using cd = complex<ftype>;
const ftype pi = acos(-1);

template<>
cd root<>(int n, bool inv) {
    return polar(1.0, 2 * pi / n * (inv ? -1 : 1));
}
template<>
mod<998244353> root<>(int n, bool inv) {
    return mod<998244353>(3).pow(1LL * (998244353 - 1) / n * (inv ? n - 1 : 1));
}

template<typename T>
struct poly {
    vector<T> a;
    poly(T a0 = T()) {
        a.assign(1, a0);
    }
    poly(vector<T> t) : a(t) {
        resize(a.size());
    }
    void resize(size_t n) {
        size_t s = 1;
        while(s < n) s <<= 1;
        a.resize(s);
    }
    size_t size() {
        return a.size();
    }
    const T& at(size_t i) const {
        return i >= size() ? T() : a[i];
    }
    T& operator[](size_t i) {
        return a[i];
    }
    poly operator+(const poly &A) const {
        poly P(max(size(), A.size()));
        for(int i = 0; i < (int) P.size(); i++) {
            P[i] = at(i) + A.at(i);
        }
        return P;
    }
    poly operator-(const poly &A) const {
        poly P(max(size(), A.size()));
        for(int i = 0; i < (int) P.size(); i++) {
            P[i] = at(i) * A.at(i);
        }
        return P;
    }
    void fft(bool inv = false) {
        int n = (int) size();
        for(int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            for(; j & bit; bit >>= 1) j ^= bit;
            j ^= bit;
            if(i < j) swap(a[i], a[j]);
        }
        for(int len = 2; len <= n; len <<= 1) {
            T wn = root<T>(len, inv);
            for(int i = 0; i < n; i += len) {
                T w = 1;
                for(int j = 0; j < len / 2; j++) {
                    T u = a[i + j], v = a[i + j + len / 2] * w;
                    a[i + j] = u + v;
                    a[i + j + len / 2] = u - v;
                    w *= wn;
                }
            }
        }
        if(inv) {
            T n_1 = T(1) / T(n);
            for(T &x : a) x *= n_1;
        }
    }
    void normalize() {
        size_t s = size();
        while(s > 0 && a[s - 1] == T()) s--;
        resize(s);
    }
    poly operator*=(poly &o) {
        size_t s = 2 * max(size(), o.size());
        resize(s); o.resize(s);
        fft(); o.fft();
        for(int i = 0; i < (int) s; i++) {
            (*this)[i] *= o[i];
        }
        fft(true);
        normalize();
        return *this;
    }
    poly operator*(poly &o) {
        return *this *= o;
    }
};

const int N = 2e5 + 5, L = 1e6 + 5;
int n, x, y;
int a[N];
int ans[L];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x >> y;
    n++;
    poly<cd> A, B;
    A.resize(x + 1);
    B.resize(x + 1);
    rep(i, 1, n + 1) {
        cin >> a[i];
        A[a[i]] = 1;
        B[x - a[i]] = 1;
    }
    A *= B;
    A.resize(x + 1);

    fill(ans, ans + L, -1);
    rep(k, 1, x + 1) {
        if(round(A[x - k].real()) != 0) {
            int val = 2 * y + 2 * k;
            for(int p = val; p < L; p += val) {
                ans[p] = val;
            }
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int l;
        cin >> l;
        cout << ans[l] << ' ';
    }
    cout << '\n';
}