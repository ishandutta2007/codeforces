
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
    mod(long long xx, bool safe = false) : x(xx) {
        if(safe && abs(x) >= m) x %= m;
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
        return mod(x * a.x, true);
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

const int M = 1e9 + 7;
using base = mod<M>;

mat<base, 10, 10> A[20];

void solve() {
    int n, m;
    cin >> n >> m;
    mat<base, 10, 10> X(1);
    array<base, 10> cnt{};
    while(n > 0) {
        cnt[n % 10] += 1;
        n /= 10;
    }
    rep(i, 0, 20) {
        if(m >> i & 1) cnt = A[i] * cnt;
    }
    base sum = 0;
    rep(i, 0, 10) sum += cnt[i];
    cout << sum << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    A[0] = mat<base, 10, 10>(0);
    rep(d, 0, 9) A[0][d + 1][d] = 1;
    A[0][1][9] = 1;
    A[0][0][9] = 1;
    rep(i, 1, 20) A[i] = A[i - 1] * A[i - 1];

    int te;
    cin >> te;
    while(te--) solve();
}