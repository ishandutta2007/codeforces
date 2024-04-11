
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// grows polynomially fast usually
// let n - p + 1 be the first index of a positive number
// answer grows polynomially in p
// if p is small, we can binary search on matrices O(log^2 k p^3)
// if p is large, we directly simulate in O(n * k^1/p)
// good for p = 12

const int N = 2e5 + 5, P = 12;
int n;
ll k, a[N];

ll mul(ll a, ll b) {
    if(a > 0 && (k + a - 1) / a <= b) {
        return k;
    }else {
        return a * b;
    }
}

struct mat {
    ll a[P][P];
    mat() {
        rep(i, 0, P) rep(j, 0, P) {
            a[i][j] = 0;
        }
    }
    mat operator*(const mat &o) const {
        mat res;
        rep(l, 0, P) rep(i, 0, P) rep(j, 0, P) {
            res.a[i][j] = min(k, res.a[i][j] + mul(a[i][l], o.a[l][j]));
        }
        return res;
    }
    array<ll, P> operator*(const array<ll, P> &o) const {
        array<ll, P> res;
        fill(all(res), 0);
        rep(i, 0, P) rep(j, 0, P) {
            res[i] = min(k, res[i] + mul(a[i][j], o[j]));
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    int p = n;
    for(int i = n; i >= 1; i--) {
        if(a[i] > 0) {
            p = n - i + 1;
        }
    }
    if(p <= P) {
        // binary search on matrices
        ll L = 0, R = k + 5;
        mat X;
        rep(i, 0, p) rep(j, i, p) {
            X.a[i][j] = 1;
        }
        while(L < R) {
            ll m = L + (R - L) / 2;
            // take X^m * f
            array<ll, P> f;
            fill(all(f), 0);
            rep(i, 0, p) {
                f[i] = a[n - i];
            }
            mat M = X;
            mat Mres;
            rep(i, 0, P) Mres.a[i][i] = 1;
            ll b = m;
            while(b > 0) {
                if(b & 1) {
                    Mres = Mres * M;
                }
                b /= 2;
                M = M * M;
            }
            f = Mres * f;
            if(f[0] < k) {
                L = m + 1;
            }else {
                R = m;
            }
        }
        cout << L << '\n';
    }else {
        // simulate
        int it = 0;
        while(true) {
            rep(i, 1, n + 1) {
                if(a[i] >= k) {
                    cout << it << '\n';
                    return 0;
                }
                a[i] += a[i - 1];
            }
            it++;
        }
    }
}