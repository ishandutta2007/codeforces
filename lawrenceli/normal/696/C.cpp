#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

ll exp(ll b, ll e) {
    if (!e) return 1;
    if (e & 1) return exp(b, e - 1) * b % mod;
    ll res = exp(b, e >> 1);
    return res * res % mod;
}

struct mat {
    int a[2][2];
    mat operator*(mat m) {
        mat ret = mat();
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    ret.a[i][k] = (ret.a[i][k] + ll(a[i][j]) * m.a[j][k] % mod) % mod;
        return ret;
    }
};

mat exp(mat b, ll e) {
    if (!e) {
        mat m = mat();
        m.a[0][0] = 1, m.a[0][1] = 0, m.a[1][0] = 0, m.a[1][1] = 1;
        return m;
    } else if (e & 1) return exp(b, e - 1) * b;
    mat res = exp(b, e >> 1);
    return res * res;
}

int K;
ll n;

int main() {
    cin >> K;
    n = 1;
    for (int i = 0; i < K; i++) {
        ll a; cin >> a;
        n = (n * (a % (mod - 1))) % (mod - 1);
    }

    n = (n + mod - 2) % (mod - 1);

    mat x = mat(); x.a[0][0] = 0, x.a[0][1] = 1, x.a[1][0] = 2, x.a[1][1] = 1;
    mat m = exp(x, n);
    mat y = mat(); y.a[0][0] = 0, y.a[0][1] = 1, y.a[1][0] = 1, y.a[1][1] = 1;
    //cout << m.a[0][0] << ' ' << m.a[0][1] << ' ' << m.a[1][0] << ' ' << m.a[1][1] << endl;
    m = m * y;
    ll pw2 = exp(2, n);

    cout << m.a[0][0] << '/' << pw2 << '\n';
}