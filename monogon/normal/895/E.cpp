
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

// expected value of a[i]
// P(swap) * (expected value from range) + (1 - P) * a[i]
// P = 1/(length)
// segment tree, apply linear function
// linearity of EV

const int N = 1e5 + 5;
int n, q;
double a[N], tree[4 * N], lazyA[4 * N], lazyB[4 * N];

void build(int i, int l, int r) {
    lazyA[i] = 1;
    lazyB[i] = 0;
    if(l == r) {
        tree[i] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}

// A2 ( A x + b) + b2
// A2 * A x + (A2 b + b2)

void prop(int i, int l, int r) {
    tree[i] = lazyA[i] * tree[i] + lazyB[i] * (r - l + 1);
    if(l < r) {
        lazyA[2 * i + 1] *= lazyA[i];
        lazyA[2 * i + 2] *= lazyA[i];
        lazyB[2 * i + 1] = lazyA[i] * lazyB[2 * i + 1] + lazyB[i];
        lazyB[2 * i + 2] = lazyA[i] * lazyB[2 * i + 2] + lazyB[i];
    }
    lazyA[i] = 1;
    lazyB[i] = 0;
}

// sum of range
double query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return 0;
    prop(i, l, r);
    if(L <= l && r <= R) return tree[i];
    int m = (l + r) / 2;
    return query(2 * i + 1, l, m, L, R) + query(2 * i + 2, m + 1, r, L, R);
}
void upd(int i, int l, int r, int L, int R, double A, double B) {
    prop(i, l, r);
    if(r < L || R < l) return;
    prop(i, l, r);
    if(L <= l && r <= R) {
        lazyA[i] *= A;
        lazyB[i] = A * lazyB[i] + B;
        prop(i, l, r);
        return;
    }
    int m = (l + r) / 2;
    upd(2 * i + 1, l, m, L, R, A, B);
    upd(2 * i + 2, m + 1, r, L, R, A, B);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    build(0, 1, n);
    cout << fixed << setprecision(6);
    while(q--) {
        int ty, l1, r1, l2, r2, l, r;
        cin >> ty;
        if(ty == 1) {
            cin >> l1 >> r1 >> l2 >> r2;
            double P1 = 1.0 / (r1 - l1 + 1);
            double P2 = 1.0 / (r2 - l2 + 1);
            double exp1 = query(0, 1, n, l1, r1) * P1;
            double exp2 = query(0, 1, n, l2, r2) * P2;
            upd(0, 1, n, l1, r1, 1 - P1, P1 * exp2);
            upd(0, 1, n, l2, r2, 1 - P2, P2 * exp1);
        }else {
            cin >> l >> r;
            cout << query(0, 1, n, l, r) << '\n';
        }
    }
}