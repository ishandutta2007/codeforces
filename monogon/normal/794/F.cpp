
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

struct node {
    ll sum[10];
    node() {
        fill(sum, sum + 10, 0);
    }
    node(ll val) {
        fill(sum, sum + 10, 0);
        ll mul = 1;
        while(val > 0) {
            sum[val % 10] += mul;
            mul *= 10;
            val /= 10;
        }
    }
    node operator+(const node &o) const {
        node x;
        rep(i, 0, 10) x.sum[i] = sum[i] + o.sum[i];
        return x;
    }
};
struct lz {
    int ch[10];
    bool flag = false;
    lz() {
        reset();
    }
    void upd(int x, int y) {
        rep(i, 0, 10) {
            if(ch[i] == x) {
                ch[i] = y;
                flag = true;
            }
        }
    }
    lz upd(const lz &o) const {
        lz x;
        rep(i, 0, 10) {
            x.ch[i] = o.ch[ch[i]];
        }
        x.flag = true;
        return x;
    }
    void reset() {
        flag = false;
        rep(i, 0, 10) ch[i] = i;
    }
    node apply(const node &o) const {
        node x;
        rep(i, 0, 10) {
            x.sum[ch[i]] += o.sum[i];
        }
        return x;
    }
};

const int N = 1e5 + 5;
int n, q;
ll a[N];
node tree[4 * N];
lz lazy[4 * N];

void build(int i, int l, int r) {
    if(l == r) {
        tree[i] = node(a[l]);
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}
void prop(int i, int l, int r) {
    if(!lazy[i].flag) return;
    tree[i] = lazy[i].apply(tree[i]);
    if(l < r) {
        lazy[2 * i + 1] = lazy[2 * i + 1].upd(lazy[i]);
        lazy[2 * i + 2] = lazy[2 * i + 2].upd(lazy[i]);
    }
    lazy[i].reset();
}
node query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return node();
    prop(i, l, r);
    if(L <= l && r <= R) return tree[i];
    int m = (l + r) / 2;
    return query(2 * i + 1, l, m, L, R) + query(2 * i + 2, m + 1, r, L, R);
}
void upd(int i, int l, int r, int L, int R, int x, int y) {
    prop(i, l, r);
    if(r < L || R < l) return;
    if(L <= l && r <= R) {
        lazy[i].upd(x, y);
        prop(i, l, r);
        return;
    }
    int m = (l + r) / 2;
    upd(2 * i + 1, l, m, L, R, x, y);
    upd(2 * i + 2, m + 1, r, L, R, x, y);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}

// void printtree(int dig) {
//     cout << "---" << endl;
//     rep(i, 0, n) {
//         cout << query(0, 0, n - 1, i, i).sum[dig] << ' ';
//     }
//     cout << endl;
//     cout << "---" << endl;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    rep(i, 0, n) cin >> a[i];
    build(0, 0, n - 1);
    while(q--) {
        int ty, l, r, x, y;
        cin >> ty >> l >> r;
        l--; r--;
        // printtree(8);
        if(ty == 1) {
            cin >> x >> y;
            upd(0, 0, n - 1, l, r, x, y);
        }else {
            node z = query(0, 0, n - 1, l, r);
            ll ans = 0;
            rep(i, 0, 10) {
                ans += z.sum[i] * i;
            }
            cout << ans << '\n';
        }
    }
}