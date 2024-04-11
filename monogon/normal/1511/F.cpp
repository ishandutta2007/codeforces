
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

template<typename T, int N, int M>
struct mat : array<array<T, M>, N> {
    mat(T diag = T()) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(i == j) {
                    (*this)[i][j] = diag;
                }else {
                    (*this)[i][j] = T();
                }
            }
        }
    }
    mat<T, N, M> operator+(const mat<T, N, M> &o) const {
        mat<T, N, M> X;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                X[i][j] = (*this)[i][j] + o[i][j];
            }
        }
        return X;
    }
    template<int P>
    mat<T, N, P> operator*(const mat<T, M, P> &o) const {
        mat<T, N, P> X;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < P; j++) {
                for(int k = 0; k < M; k++) {
                    X[i][j] += (*this)[i][k] * o[k][j];
                }
            }
        }
        return X;
    }
    array<T, N> operator*(const array<T, M> &x) const {
        array<T, N> y{};
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                y[i] += (*this)[i][j] * x[j];
            }
        }
        return y;
    }
    mat<T, N, M> pow(long long b) const {
        mat A = *this;
        mat X(1);
        while(b > 0) {
            if(b & 1) X = X * A;
            A = A * A;
            b /= 2;
        }
        return X;
    }
    mat<T, M, N> t() const {
        mat<T, M, N> X;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                X[j][i] = (*this)[i][j];
            }
        }
        return X;
    }
};

template<typename T, int N, int M>
ostream& operator<<(ostream &os, const mat<T, N, M> &A) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            os << A[i][j] << ' ';
        }
        os << '\n';
    }
    return os;
}

const int M = 998244353;
using base = mod<M>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, 0, n) {
        cin >> s[i];
    }
    mat<base, 200, 200> A;
    rep(x, 0, 40) {
        int i = x / 5;
        int p = x % 5;
        rep(b, 0, 4) A[x + 40 * (b + 1)][x + 40 * b] += 1;
        if(i < n && p < (int) s[i].length()) {
            if(p == (int) s[i].length() - 1) {
                rep(j, 0, n) rep(k, 0, n) {
                    int l = min(s[j].length(), s[k].length());
                    if(s[j].substr(0, l) == s[k].substr(0, l)) {
                        int y = (s[j].length() >= s[k].length() ? 5 * j + l - 1 : 5 * k + l - 1);
                        A[y][x + 40 * (l - 1)] += 1;
                    }
                }
            }else {
                rep(j, 0, n) {
                    int l = min(s[j].length(), s[i].length() - p - 1);
                    if(s[j].substr(0, l) == s[i].substr(p + 1, l)) {
                        int y = ((int) s[j].length() >= (int) s[i].length() - p - 1 ? 5 * j + l - 1 : 5 * i + p + l);
                        A[y][x + 40 * (l - 1)] += 1;
                    }
                }
            }
        }
    }

    array<base, 200> vec;
    vec[s[0].length() - 1] = 1;
    vec = A.pow(m) * vec;
    base ans = 0;
    rep(i, 0, n) ans += vec[5 * i + s[i].length() - 1];
    cout << ans << '\n';
}