
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

const int M = 1e9 + 7;

template<int K>
struct mat {
    ll a[K][K];
    mat() {
        rep(i, 0, K) rep(j, 0, K) {
            a[i][j] = 0;
        }
    }
    mat<K> operator+(const mat<K> &o) const {
        mat<K> ans;
        rep(i, 0, K) rep(j, 0, K) {
            ans.a[i][j] = (a[i][j] + o.a[i][j]) % (M - 1);
        }
        return ans;
    }
    mat<K> operator*(const mat<K> &o) const {
        mat<K> ans;
        rep(i, 0, K) rep(j, 0, K) rep(k, 0, K) {
            ans.a[i][j] = (ans.a[i][j] + a[i][k] * o.a[k][j]) % (M - 1);
        }
        return ans;
    }
    array<ll, K> operator*(const array<ll, K> &o) const {
        array<ll, K> ans;
        fill(ans.begin(), ans.end(), 0);
        rep(i, 0, K) rep(j, 0, K) {
            ans[i] = (ans[i] + a[i][j] * o[j]) % (M - 1);
        }
        return ans;
    }
};

ll n, f1, f2, f3, c;

ll powmod(ll a, ll b) {
    ll ans = 1;
    while(b > 0) {
        if(b & 1) {
            ans = (ans * a) % M;
        }
        b /= 2;
        a = (a * a) % M;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> f1 >> f2 >> f3 >> c;
    mat<14> A;
    rep(i, 0, 4) {
        A.a[i][i] = 1;
        A.a[i][i + 4] = 1;
        A.a[i][i + 8] = 1;
        A.a[i + 4][i] = 1;
        A.a[i + 8][i + 4] = 1;
    }
    A.a[0][12] = 2;
    A.a[0][13] = -4;
    A.a[12][12] = A.a[12][13] = A.a[13][13] = 1;
    mat<14> X;
    rep(i, 0, 14) X.a[i][i] = 1;
    array<ll, 14> f;
    fill(f.begin(), f.end(), 0);
    f[3] = f[6] = f[9] = f[13] = 1;
    f[12] = 3;
    n -= 3;
    while(n > 0) {
        if(n & 1) {
            X = X * A;
        }
        n /= 2;
        A = A * A;
    }
    // while(n--) X = X * A;
    f = X * f;
    // rep(i, 0, 14) {
    //     cout << f[i] << ' ';
    //     if(i == 13) cout << endl;
    // }
    ll ans = (((powmod(c, f[0]) * powmod(f1, f[1])) % M) * ((powmod(f2, f[2]) * powmod(f3, f[3])) % M)) % M;
    ans = (ans + M) % M;
    cout << ans << '\n';
}