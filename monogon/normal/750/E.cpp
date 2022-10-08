
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

// last 2017, must delete all 6's after the 1
// (delete all 2016) 2 (delete all 016) 0 (delete all 16) 1 (delete all 6) 7 (delete all 6)

// min operations to delete ab
// (delete a) (delete b)
// min operations to delete abc
// (delete a) (delete b) (delete c)
// min way of splitting into segments like this, a segment can be empty

// 0  -> 2
// 1  -> 0
// 2  -> 1
// 3  -> 6
// 4  -> 20
// 5  -> 01
// 6  -> 16
// 7  -> 201
// 8  -> 016
// 9  -> 2016

// 9 1
// 201216017
// 1 9

struct node {
    int a[10];
    node() {
        rep(i, 0, 10) a[i] = 0;
    }
    node(char c) {
        rep(i, 0, 10) a[i] = 0;
        if(c == '2') a[0] = 1;
        else if(c == '0') a[1] = 1;
        else if(c == '1') a[2] = 1;
        else if(c == '6') a[3] = 1;
    }
    node operator+(const node &o) const {
        node x;
        x.a[0] = a[0] + o.a[0];
        x.a[1] = a[1] + o.a[1];
        x.a[2] = a[2] + o.a[2];
        x.a[3] = a[3] + o.a[3];
        x.a[4] = min(a[4] + o.a[1], a[0] + o.a[4]);
        x.a[5] = min(a[5] + o.a[2], a[1] + o.a[5]);
        x.a[6] = min(a[6] + o.a[3], a[2] + o.a[6]);
        x.a[7] = min({a[0] + o.a[7], a[4] + o.a[5], a[7] + o.a[2]});
        x.a[8] = min({a[1] + o.a[8], a[5] + o.a[6], a[8] + o.a[3]});
        x.a[9] = min({a[0] + o.a[9], a[4] + o.a[8], a[7] + o.a[6], a[9] + o.a[3]});
        return x;
    }
};

const int N = 2e5 + 5;
node tree[4 * N];

void build(int i, int l, int r, const string &s) {
    if(l == r) {
        tree[i] = node(s[l]);
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m, s);
    build(2 * i + 2, m + 1, r, s);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}
node query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return node();
    if(L <= l && r <= R) return tree[i];
    int m = (l + r) / 2;
    return query(2 * i + 1, l, m, L, R) + query(2 * i + 2, m + 1, r, L, R);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = "$" + s;
    build(0, 1, n, s);
    vector<vi> nxt(n + 1, vi(10, 0));
    rep(i, 1, n + 1) {
        nxt[i] = nxt[i - 1];
        nxt[i][s[i] - '0'] = i;
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        int p2017 = nxt[r][7];
        int p201 = nxt[p2017][1];
        int p20 = nxt[p201][0];
        int p2 = nxt[p20][2];
        if(p2 < l) {
            cout << -1 << '\n';
            continue;
        }
        node x4 = query(0, 1, n, p201, r);
        node x3 = query(0, 1, n, p20, p201);
        node x2 = query(0, 1, n, p2, p20);
        node x1 = query(0, 1, n, l, p2);
        // 9863, 863, 63, 3
        int ans = min({
            x1.a[9] + x2.a[3] + x3.a[3],
            x1.a[7] + x2.a[6] + x3.a[3],
            x1.a[7] + x2.a[2] + x3.a[6],
            x1.a[4] + x2.a[8] + x3.a[3],
            x1.a[4] + x2.a[5] + x3.a[6],
        }) + x4.a[3];
        cout << ans << '\n';
    }
}