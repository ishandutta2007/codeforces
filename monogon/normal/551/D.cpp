
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

// if k >= 2^l answer is 0
// bit 1 => at least two adjacent 1's
// bit 0 => no two adjacent 1's
// so, number of independent sets on a path for bit 0, or 2^n - this for a bit 1
// multiply all together
// f[n] = number of indep. sets on a path of length n
// f[n] = f[n - 1] + f[n - 2], just fibonacci
// f[0] = 1, f[1] = 2
// 2 => 3
// 3 => 5
// 4 => 8
// 0000 1000 0100 0010 0001 1001 0101 1010
// fibonacci mod m
// binary exponentiation

// f[i + 1] = [ 1 1 ] f[i]
// f[i]       [ 1 0 ] f[i - 1]

ll n, k, l, m;

ll mod(ll a) {
    return ((a % m) + m) % m;
}

struct mat {
    ll a[2][2];
    mat() {
        rep(i, 0, 2) rep(j, 0, 2) a[i][j] = 0;
    }
    mat operator+(const mat &o) const {
        mat res;
        rep(i, 0, 2) rep(j, 0, 2) res.a[i][j] = mod(a[i][j] + o.a[i][j]);
        return res;
    }
    mat operator*(const mat &o) const {
        mat res;
        rep(i, 0, 2) rep(j, 0, 2) rep(k, 0, 2) {
            res.a[i][j] = mod(res.a[i][j] + a[i][k] * o.a[k][j]);
        }
        return res;
    }
};

ll fib(ll k) {
    mat M, M2;
    M2.a[0][0] = M2.a[1][1] = 1;
    M.a[0][0] = M.a[0][1] = M.a[1][0] = 1;
    while(k > 0) {
        if(k & 1) {
            M2 = M2 * M;
        }
        M = M * M;
        k /= 2;
    }
    return M2.a[1][0];
}
ll powmod(ll a, ll b) {
    ll ans = 1;
    while(b > 0) {
        if(b & 1) {
            ans = mod(ans * a);
        }
        a = mod(a * a);
        b /= 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> l >> m;
    if(l < 63 && (k >> l) > 0) {
        cout << "0\n";
        return 0;
    }
    ll f = fib(n + 2);
    ll ans = 1;
    ll f2 = mod(powmod(2, n) - f);
    rep(i, 0, l) {
        if((k >> i) & 1) {
            ans = mod(ans * f2);
        }else {
            ans = mod(ans * f);
        }
    }
    cout << mod(ans) << '\n';
}