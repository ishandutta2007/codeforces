#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> pol;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

const int mod = 998244353;
const int root = 3;

void add(int &a, int b){
    a += b;
    if (a >= mod)
        a -= mod;
}

void sub(int &a, int b){
    a -= b;
    if (a < 0)
        a += mod;
}

int modexp(int a, int n){
    int ans = 1;
    while (n){
        if (n & 1) ans = 1LL * ans * a % mod;
        n >>= 1;
        a = 1LL * a * a % mod;
    }
    return ans;
}

const int i2 = modexp(2, mod - 2);

void fft(vector<int> &x, int sign = +1)
{
    int n = x.size();
    int h = modexp(root, (mod - 1) / n);
    if (sign < 0) h = modexp(h, mod - 2);
    for (int i = 0, j = 1; j < n - 1; ++j)
    {
        for (int k = n >> 1; k > (i ^= k); k >>= 1);
        if (j < i) swap(x[i], x[j]);
    }
    for (int m = 1; m < n; m *= 2)
    {
        int w = 1, wk = modexp(h, n / (2 * m));
        for (int i = 0; i < m; ++i)
        {
            for (int j = i; j < n; j += 2 * m)
            {
                int u = x[j], d = 1LL * x[j + m] * w % mod;
                if ((x[j] = u + d) >= mod)
                    x[j] -= mod;
                if ((x[j + m] = u - d) < 0)
                    x[j + m] += mod;
            }
            w = 1LL * w * wk % mod;
        }
    }
    if (sign < 0)
    {
        int n_inv = modexp(n, mod - 2);
        for (auto &a : x)
            a = (1LL * a * n_inv) % mod;
    }
}


void multiply(pol &a, pol b){
    int sz = 2 * (int)a.size();

    a.resize(sz); fft(a, +1);
    b.resize(sz); fft(b, +1);

    for (int i = 0; i < sz; ++i)
        a[i] = 1LL * a[i] * b[i] % mod;

    fft(a, -1);

    a.resize(sz / 2);
}

pol inverse(pol &a){
    assert(a[0] != 0);

    pol r(1, modexp(a[0], mod - 2));

    while (r.size() < a.size()){
        int csize = 2 * (int)r.size();

        r.resize(csize);
        pol tr = r;
        tr.resize(2 * csize);
        pol tf(2 * csize); for (int i = 0; i < csize; ++i) tf[i] = a[i];

        fft(tr, +1);
        fft(tf, +1);

        for (int i = 0; i < 2 * csize; ++i)
            tr[i] = 1LL * tr[i] * tr[i] % mod * tf[i] % mod;

        fft(tr, -1);

        for (int i = 0; i < csize; ++i){
            add(r[i], r[i]);
            sub(r[i], tr[i]);
        }
    }

    return r;
}

pol sqrt(pol &a){
    // rt^2 = a[0] (mod)
    // this only works if a[0] = 1
    int rt = 1;

    pol r(1, rt);

    while (r.size() < a.size()){
        int csize = 2 * (int)r.size();

        r.resize(csize);
        pol tf(csize); for (int i = 0; i < csize; ++i) tf[i] = a[i];
        pol ir = inverse(r);

        multiply(tf, ir);

        for (int i = 0; i < csize; ++i){
            add(r[i], tf[i]);
            r[i] = 1LL * r[i] * i2 % mod;
        }
    }

    return r;
}

pol pow(pol a, int n){
    pol r(a.size());
    r[0] = 1;

    for (;n; n >>= 1){
        if (n & 1) multiply(r, a);
        multiply(a, a);
    }

    return r;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int sz = 1;
    while (sz <= k) sz *= 2;

    pol d = {1, 6, 1};
    d.resize(sz);
    pol r = sqrt(d);

    pol x1 = {1, 1};
    x1.resize(sz);
    pol x2 = x1;

    for (int i = 0; i < sz; ++i){
        add(x1[i], r[i]);
        x1[i] = 1LL * x1[i] * i2 % mod;

        sub(x2[i], r[i]);
        x2[i] = 1LL * x2[i] * i2 % mod;
    }

    pol A = x2, M2 = x2;
    sub(A[0], 1); sub(A[1], 1);

    for (int i = 0; i < sz; ++i)
        sub(M2[i], x1[i]);

    M2 = inverse(M2);

    multiply(A, M2);

    pol B = A;

    for (int i = 0; i < sz; ++i)
        B[i] = B[i] ? mod - B[i] : 0;

    add(B[0], 1);

    x1 = pow(x1, n);
    x2 = pow(x2, n);

    multiply(x1, A);
    multiply(x2, B);

    for (int i = 0; i < sz; ++i)
        add(x1[i], x2[i]);

    for (int i = 1; i <= k; ++i)
        cout << x1[i] << " ";

    cout << endl;

    return 0;
}