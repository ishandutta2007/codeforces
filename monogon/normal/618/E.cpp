
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

using ftype = long double;
const ftype pi = acosl(-1);

struct pt {
    ftype x, y;
    pt(ftype x = 0, ftype y = 0) : x(x), y(y) {}
    pt operator+(const pt &o) const {
        return pt(x + o.x, y + o.y);
    }
    void operator*=(const ftype f) {
        x *= f;
        y *= f;
    }
    ftype len() const {
        return hypotl(x, y);
    }
};

const int N = 3e5 + 5;
pt tree[4 * N];
int lazy[4 * N];

void build(int i, int l, int r) {
    lazy[i] = 0;
    if(l == r) {
        tree[i] = pt(1, 0);
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}
void prop(int i, int l, int r) {
    // rotate
    if(lazy[i] == 0) return;
    ftype ang = (lazy[i] * pi) / 180.0;
    ftype c = cosl(ang), s = sinl(ang);
    ftype x = tree[i].x * c - tree[i].y * s;
    ftype y = tree[i].x * s + tree[i].y * c;
    tree[i] = pt(x, y);
    if(l < r) {
        lazy[2 * i + 1] += lazy[i];
        lazy[2 * i + 2] += lazy[i];
    }
    lazy[i] = 0;
}
void upd(int i, int l, int r, int L, int R, int z) {
    prop(i, l, r);
    if(r < L || R < l) return;
    if(L <= l && r <= R) {
        lazy[i] = z;
        prop(i, l, r);
        return;
    }
    int m = (l + r) / 2;
    upd(2 * i + 1, l, m, L, R, z);
    upd(2 * i + 2, m + 1, r, L, R, z);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}
void upd2(int i, int l, int r, int k, int z) {
    prop(i, l, r);
    if(l == r) {
        ftype len = tree[i].len();
        tree[i] *= (len + z) / len;
        return;
    }
    int m = (l + r) / 2;
    if(k <= m) {
        upd2(2 * i + 1, l, m, k, z);
        prop(2 * i + 2, m + 1, r);
    }
    else {
        upd2(2 * i + 2, m + 1, r, k, z);
        prop(2 * i + 1, l, m);
    }
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}
pt query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return pt();
    prop(i, l, r);
    if(L <= l && r <= R) {
        return tree[i];
    }
    int m = (l + r) / 2;
    return query(2 * i + 1, l, m, L, R) + query(2 * i + 2, m + 1, r, L, R);
}

void printtree(int n) {
    rep(i, 1, n + 1) {
        pt p = query(0, 1, n, i, i);
        cout << "(" << p.x << ", " << p.y << ") ";
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    build(0, 1, n);
    cout << fixed << setprecision(6);
    rep(i, 0, m) {
        int x, y, z;
        cin >> x >> y >> z;
        if(x == 1) {
            // y = segment, z = length
            upd2(0, 1, n, y, z);
        }else {
            // y = segment, z = angle in degrees
            upd(0, 1, n, y, n, z);
        }
        pt p = query(0, 1, n, 1, n);
        cout << p.x << ' ' << -p.y << '\n';
        // printtree(n);
    }
}