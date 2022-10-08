
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

// template<typename T>
// struct sos {
//     int n;
//     vector<T> a;
//     sos(size_t n) : n(n), a(1 << n) {}
//     void clear() {
//         fill(a.begin(), a.end(), T());
//     }
//     void flip() {
//         for(int i = 0; i < (1 << (n - 1)); i++) {
//             swap(a[i], a[i ^ ((1 << n) - 1)]);
//         }
//     }
//     void zeta() {
//         for(int i = 0; i < n; i++) {
//             for(int s = 0; s < (1 << n); s++) {
//                 if(s >> i & 1) {
//                     a[s] = a[s] + a[s ^ (1 << i)];
//                 }
//             }
//         }
//     }
//     void supzeta() {
//         for(int i = n - 1; i >= 0; i--) {
//             for(int s = (1 << n) - 1; s >= 0; s--) {
//                 if(~s >> i & 1) {
//                     a[s] = a[s] + a[s ^ (1 << i)];
//                 }
//             }
//         }
//     }
//     void mobius() {
//         for(int i = n - 1; i >= 0; i--) {
//             for(int s = (1 << n) - 1; s >= 0; s--) {
//                 if(s >> i & 1) {
//                     a[s] = a[s] - a[s ^ (1 << i)];
//                 }
//             }
//         }
//     }
//     void supmobius() {
//         for(int i = 0; i < n; i++) {
//             for(int s = 0; s < n; s++) {
//                 if(~s >> i & 1) {
//                     a[s] = a[s] - a[s ^ (1 << i)];
//                 }
//             }
//         }
//     }
// };

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
// using base = double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<base> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    vector<base> p(1 << n);
    vector<base> thonk(n);
    rep(mask, 1, 1 << n) {
        p[mask] = 1;
        fill(all(thonk), 0);
        rep(i, 0, n) if(mask >> i & 1) {
            thonk[i] = 1;
            rep(j, 0, n) if(~mask >> j & 1) {
                thonk[i] *= (a[i] / (a[i] + a[j]));
            }
            p[mask] *= thonk[i];
        }
        for(int s = (mask - 1) & mask; s > 0; s = (s - 1) & mask) {
            base P = p[s];
            rep(i, 0, n) if((mask >> i & 1) && (~s >> i & 1)) {
                P *= thonk[i];
                // rep(j, 0, n) if(~mask >> j & 1) {
                    // P *= (a[i] / (a[i] + a[j]));
                // }
            }
            p[mask] -= P;
        }
    }
    base ans = 0;
    rep(mask, 0, 1 << n) {
        ans += p[mask] * base(__builtin_popcount(mask));
        // cout << mask << ' ' << p[mask] << '\n';
    }
    cout << ans << '\n';
}