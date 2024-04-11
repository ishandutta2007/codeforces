
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
    size_t deg;
    poly(T a0 = T()) {
        a.assign(1, a0);
        deg = 0;
    }
    poly(vector<T> t) : a(t) {
        assert(!t.empty());
        resize(a.size());
        deg = t.size() - 1;
    }
    void resize(size_t n) {
        deg = min(deg, n - 1);
        size_t s = 1;
        while(s < n) s <<= 1;
        a.resize(s);
    }
    size_t size() const {
        return a.size();
    }
    const T operator[](size_t i) const {
        return i > deg ? T() : a[i];
    }
    void set(size_t i, const T &t) {
        deg = max(deg, i);
        resize(deg + 1);
        a[i] = t;
    }
    poly operator+(const poly &A) const {
        poly P;
        P.resize(max(size(), A.size()));
        for(size_t i = 0; i < P.size(); i++) {
            P.a[i] = (*this)[i] + A[i];
        }
        P.deg = max(deg, A.deg);
        return P;
    }
    poly operator+=(const poly A) {
        return *this = *this + A;
    }
    poly operator-(const poly A) const {
        poly P;
        P.resize(max(size(), A.size()));
        for(int i = 0; i < (int) P.size(); i++) {
            P.a[i] = (*this)[i] - A[i];
        }
        P.deg = max(deg, A.deg);
        return P;
    }
    poly operator-=(const poly A) {
        return *this = *this - A;
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
    poly mod_xk(size_t k) const {
        poly P;
        P.resize(k);
        for(size_t i = 0; i < k; i++) P.a[i] = (*this)[i];
        P.deg = min(k - 1, deg);
        return P;
    }
    poly& operator*=(const poly &o) {
        size_t s = 2 * max(size(), o.size());
        resize(s);
        poly B = o;
        B.resize(s);
        fft(); B.fft();
        for(size_t i = 0; i < s; i++) {
            a[i] *= B.a[i];
        }
        fft(true);
        deg = deg + o.deg;
        resize(deg + 1);
        return *this;
    }
    poly operator*(const poly &o) const {
        poly A = *this;
        A *= o;
        return A;
    }
    poly& operator*=(const T &t) {
        for(size_t i = 0; i <= deg; i++) {
            a[i] *= t;
        }
        return *this;
    }
    poly operator*(const T &t) const {
        poly A = *this;
        A *= t;
        return A;
    }
    poly deriv() const {
        poly P;
        P.resize(deg);
        for(int i = 1; i <= (int) deg; i++) {
            P.a[i - 1] = a[i] * T(i);
        }
        P.deg = max(size_t(1), deg) - 1;
        return P;
    }
    poly integ() const {
        poly P;
        P.resize(deg + 2);
        for(size_t i = 0; i <= deg; i++) {
            P.a[i + 1] = a[i] / T(i + 1);
        }
        P.deg = deg + 1;
        return P;
    }
    poly mul_xk(size_t k) const {
        poly P;
        P.resize(deg + k + 1);
        for(size_t i = 0; i <= deg; i++) {
            P.a[i + k] = a[i];
        }
        P.deg = deg + k;
        return P;
    }
    poly div_xk(size_t k) const {
        k = min(k, size());
        poly P;
        P.resize(deg - k + 1);
        for(size_t i = k; i <= deg; i++) {
            P.a[i - k] = a[i];
        }
        P.deg = deg - k;
        return P;
    }
    poly inv(size_t n) const {
        poly Q = T(1) / a[0];
        for(size_t s = 2; s < n * 2; s <<= 1) {
            Q *= (poly(2) - Q * mod_xk(s));
            Q.resize(s);
        }
        Q.deg = n - 1;
        return Q;
    }
    poly log(size_t n) const {
        return (deriv().mod_xk(n) * inv(n)).integ().mod_xk(n);
    }
    poly exp(size_t n) const {
        poly Q = T(1);
        for(size_t s = 2; s < n * 2; s <<= 1) {
            Q *= (poly(1) + mod_xk(s) - Q.log(s));
            Q.resize(s);
        }
        Q.deg = n - 1;
        return Q;
    }
};

template<int m>
void print(const poly<mod<m>> &P) {
    cout << P[0]();
    for(size_t i = 1; i <= P.deg; i++) {
        cout << " + " << P[i]() << " x^" << i;
    }
    cout << '\n';
}
void print(const poly<cd> &P) {
    cout << round(P[0].real());
    for(size_t i = 1; i <= P.deg; i++) {
        cout << " + " << round(P[i].real()) << " x^" << i;
    }
    cout << '\n';
}
void printreal(const poly<cd> &P) {
    cout << round(P[0].real());
    for(size_t i = 1; i <= P.deg; i++) {
        cout << " + " << P[i].real() << " x^" << i;
    }
    cout << '\n';
}

const int M = 998244353;
using base = mod<M>;
const int N = 1e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    poly<base> C;
    int minc = N;
    rep(i, 0, n) {
        int c; cin >> c;
        C.set(c, 2);
        minc = min(minc, c);
    }
    poly<base> P = poly<base>(1) - ((poly<base>(1) - C * 2).log(2 * N) * base(2).inv()).exp(2 * N);
    // print(P);
    // print(C);
    P = (P.div_xk(minc) * C.div_xk(minc).inv(N)).mod_xk(N);
    // print(P);
    rep(i, 1, m + 1) {
        cout << P[i]() << '\n';
    }
}