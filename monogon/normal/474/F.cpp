
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

// how many largest ants?
// do all ants on interval divide x?
// a | x, b | x => lcm(a, b) | x
// x = k * prod / gcd(a, b)
// segment tree LCM
// if LCM is too large, store 1e9 + 5 instead

const int N = 1e5 + 5;
int n, t, l, r, s[N];

struct node {
    int mn, occ, g;
    node(int mn = 1e9 + 5, int occ = 0, ll g = 0): mn(mn), occ(occ), g(g) {}
    node operator+(const node &o) const {
        node x;
        x.mn = min(mn, o.mn);
        x.occ = (mn == x.mn ? occ : 0) + (o.mn == x.mn ? o.occ : 0);
        x.g = gcd(g, o.g);
        return x;
    }
} tree[4 * N];

void build(int i, int l, int r) {
    if(l == r) {
        tree[i] = node(s[l], 1, s[l]);
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
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
    cin >> n;
    rep(i, 0, n) {
        cin >> s[i];
    }
    build(0, 0, n - 1);
    cin >> t;
    while(t--) {
        cin >> l >> r;
        l--; r--;
        node q = query(0, 0, n - 1, l, r);
        // cout << q.g << ' ' << q.occ << q.mn << endl;
        if(q.g == q.mn) {
            cout << (r - l + 1) - q.occ << '\n';
        }else {
            cout << (r - l + 1) << '\n';
        }
    }
}