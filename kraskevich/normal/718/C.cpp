#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 1000 * 1000 * 1000 + 7;

ll add_mod(ll a, ll b) {
    return (a + b) % MOD;
}

struct Matrix {
    ll a[2][2];

    Matrix() {
        a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0;
    }

    Matrix(ll a00, ll a01, ll a10, ll a11) {
        a[0][0] = a00;
        a[0][1] = a01;
        a[1][0] = a10;
        a[1][1] = a11;
    }

    Matrix operator*(const Matrix& r) const {
        Matrix res;
        for (int i = 0; i < 2; i++)
            for (int k = 0; k < 2; k++)
                for (int j = 0; j < 2; j++)
                    res.a[i][j] = add_mod(res.a[i][j], a[i][k] * r.a[k][j]);
        return res;
    }

    Matrix operator+(const Matrix& r) const {
        Matrix res;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                res.a[i][j] = add_mod(a[i][j], r.a[i][j]);
        return res;
    }                        

    Matrix pow(ll n) const {
        Matrix res(1, 0, 0, 1);
        Matrix x(a[0][0], a[0][1], a[1][0], a[1][1]);
        for (; n > 0; n /= 2) {
            if (n % 2 == 1)
                res = res * x;
            x = x * x;
        }
        return res; 
    }            
};

const int N = 400 * 1000 + 10;
const Matrix FIB(1, 1, 1, 0);

Matrix t[N];
Matrix add[N];
Matrix init[N];

void build(int i, int l, int r) {
    add[i] = Matrix(1, 0, 0, 1);
    if (l == r) {
        t[i] = init[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    t[i] = t[2 * i + 1] + t[2 * i + 2];
}    

void push(int i) {
    t[i] = t[i] * add[i];
    if (2 * i + 2 < N) {    
        add[2 * i + 1] = add[2 * i + 1] * add[i];
        add[2 * i + 2] = add[2 * i + 2] * add[i];
    }
    add[i] = Matrix(1, 0, 0, 1);
}

Matrix get(int i, int tl, int tr, int l, int r) {
    push(i);
    if (l == tl && r == tr)
        return t[i];
    int m = (tl + tr) / 2;
    Matrix ml;
    Matrix mr;
    if (l <= m)
        ml = get(2 * i + 1, tl, m, l, min(r, m));
    if (r > m)
        mr = get(2 * i + 2, m + 1, tr, max(m + 1, l), r);
    return ml + mr;
}    

void put(int i, int tl, int tr, int l, int r, const Matrix& a) {
    push(i);
    if (tl == l && r == tr) {
        add[i] = add[i] * a;
        return;
    }
    int m = (tl + tr) / 2;
    if (l <= m)
        put(2 * i + 1, tl, m, l, min(r, m), a);
    if (r > m)
        put(2 * i + 2, m + 1, tr, max(m + 1, l), r, a);
    t[i] = get(2 * i + 1, 0, 0, 0, 0) + get(2 * i + 2, 0, 0, 0, 0);
}     

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        init[i] = FIB.pow(x);
    }
    build(0, 0, n - 1);
    for (int i = 0; i < m; i++) {
        int tp, l, r;
        cin >> tp >> l >> r;
        l--;
        r--;
        if (tp == 1) {
            int x;
            cin >> x;
            Matrix a = FIB.pow(x);
            put(0, 0, n - 1, l, r, a);
        } else {
            cout << get(0, 0, n - 1, l, r).a[0][1] << "\n";
        } 
    }
    return 0;
}