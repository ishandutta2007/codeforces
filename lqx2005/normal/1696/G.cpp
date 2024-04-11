#include <bits/stdc++.h>
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define db double
#define ll long long
using namespace std;
const int N = 2e5 + 10;
struct matrix {
    db a[3][3];
    matrix() { FOR(i, 0, 2) FOR(j, 0, 2) a[i][j] = -1. / 0.; }
    friend matrix operator * (const matrix a, const matrix b) {
        matrix c;
        FOR(i, 0, 2) {
            FOR(j, 0, 2) {
                FOR(k, 0, 2) {
                    c.a[i][k] = max(a.a[i][j] + b.a[j][k], c.a[i][k]);
                }
            }
        }
        return c;
    }
    void see() {
        FOR(i, 0, 2) {
            FOR(j, 0, 2) {
                cout << a[i][j] <<" ";
            }
            cout << endl;
        }
    }
};
int n, q, x, y;
int arr[N];
#define mid ((l + r) >> 1)
#define ls (p + 1)
#define rs (p + ((mid - l + 1) << 1))
matrix t[N << 1];
void build(int p, int l, int r) {
    if(l == r) {
        t[p].a[0][0] = t[p].a[1][0] = t[p].a[0][1] = -1. / 0.;
        FOR(i, 0, 2) t[p].a[2][i] = 0;
        FOR(i, 1, 2) t[p].a[1][i] = 1. * arr[l] / (x + y);
        t[p].a[0][2] = 1. * arr[l] / y;
        return;
    }
    build(ls, l, mid), build(rs, mid + 1, r);
    t[p] = t[ls] * t[rs];
}
void modify(int p, int l, int r, int k) {
    if(l == r) {
        t[p].a[0][0] = t[p].a[1][0] = t[p].a[0][1] = -1. / 0.;
        FOR(i, 0, 2) t[p].a[2][i] = 0;
        FOR(i, 1, 2) t[p].a[1][i] = 1. * arr[l] / (x + y);
        t[p].a[0][2] = 1. * arr[l] / y;
        return;
    }
    if(k <= mid) modify(ls, l, mid, k);
    else modify(rs, mid + 1, r, k);
    t[p] = t[ls] * t[rs];
}
matrix query(int p, int l, int r, int L, int R) {
    if(L <= l && r <= R) return t[p];
    if(R <= mid) return query(ls, l, mid, L, R);
    if(L > mid) return query(rs, mid + 1, r, L, R);
    return query(ls, l, mid, L, mid) * query(rs, mid + 1, r, mid + 1, R);
}
int main() {
    cout.precision(20), cout << fixed;
    cin >> n >> q >> x >> y;
    if(x > y) swap(x, y);
    FOR(i, 1, n) cin >> arr[i];
    build(1, 1, n);
    FOR(i, 1, q) {
        int opt;
        cin >> opt;
        if(opt == 1) {
            int k, v;
            cin >> k >> v;
            arr[k] = v;
            modify(1, 1, n, k);
        } else {
            int l, r;
            cin >> l >> r;
            matrix st;
            FOR(j, 0, 2) st.a[0][j] = 0;
            st = st * query(1, 1, n, l, r);
            cout << st.a[0][2] << endl;
        }
    }
    return 0;
}