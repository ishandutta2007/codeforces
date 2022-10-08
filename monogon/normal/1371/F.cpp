
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

const int N = 5e5 + 5;

struct node {
    int LR, RL, preL, preR, preLR, preRL, sufL, sufR, sufLR, sufRL, len;
    node() {
        LR = RL = preL = preR = preLR = preRL = sufL = sufR = sufLR = sufRL = len = 0;
    }
    void swp() {
        swap(LR, RL);
        swap(preL, preR);
        swap(preLR, preRL);
        swap(sufL, sufR);
        swap(sufLR, sufRL);
    }
    node(char c) {
        LR = RL = 1;
        preL = 1;
        preR = 0;
        sufL = 1;
        sufR = 0;
        preLR = preRL = sufLR = sufRL = 1;
        if(c == '>') swp();
        len = 1;
    }
    node operator+(const node &o) const {
        if(len == 0) return o;
        if(o.len == 0) return *this;
        node x;
        x.preL = (preL == len ? len + o.preL : preL);
        x.preR = (preR == len ? len + o.preR : preR);
        x.sufL = (o.sufL == o.len ? o.len + sufL : o.sufL);
        x.sufR = (o.sufR == o.len ? o.len + sufR : o.sufR);
        x.preLR = (preL == len ? len + o.preLR : preLR == len ? len + o.preR : preLR);
        x.preRL = (preR == len ? len + o.preRL : preRL == len ? len + o.preL : preRL);
        x.sufLR = (o.sufR == o.len ? o.len + sufLR : o.sufLR == o.len ? o.len + sufL : o.sufLR);
        x.sufRL = (o.sufL == o.len ? o.len + sufRL : o.sufRL == o.len ? o.len + sufR : o.sufRL);
        x.RL = max({RL, o.RL, sufR + o.preRL, sufRL + o.preL});
        x.LR = max({LR, o.LR, sufL + o.preLR, sufLR + o.preR});
        x.len = len + o.len;
        return x;
    }
};
int n, q;
string s;
node tree[4 * N];
bool lazy[4 * N];

void build(int i, int l, int r) {
    if(l == r) {
        tree[i] = node(s[l]);
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}
void prop(int i, int l, int r) {
    if(!lazy[i]) return;
    tree[i].swp();
    if(l < r) {
        lazy[2 * i + 1] ^= 1;
        lazy[2 * i + 2] ^= 1;
    }
    lazy[i] = false;
}
void upd(int i, int l, int r, int L, int R) {
    prop(i, l, r);
    if(r < L || R < l) return;
    if(L <= l && r <= R) {
        lazy[i] ^= 1;
        prop(i, l, r);
        return;
    }
    int m = (l + r) / 2;
    upd(2 * i + 1, l, m, L, R);
    upd(2 * i + 2, m + 1, r, L, R);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}
node query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return node();
    prop(i, l, r);
    if(L <= l && r <= R) return tree[i];
    int m = (l + r) / 2;
    return query(2 * i + 1, l, m, L, R) + query(2 * i + 2, m + 1, r, L, R);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q >> s;
    build(0, 0, n - 1);
    while(q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        upd(0, 0, n - 1, l, r);
        cout << query(0, 0, n - 1, l, r).RL << '\n';
    }
}