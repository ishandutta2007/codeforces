
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

const int N = 1e6 + 5;

int tree[4 * N], lazy[4 * N];

void build(int i, int l, int r, const vi &amt) {
    if(l == r) {
        tree[i] = amt[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m, amt);
    build(2 * i + 2, m + 1, r, amt);
    tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
}
int get(int i) {
    return tree[i] + lazy[i];
}
void prop(int i, int l, int r) {
    if(lazy[i] == 0) return;
    tree[i] = get(i);
    if(l < r) {
        lazy[2 * i + 1] += lazy[i];
        lazy[2 * i + 2] += lazy[i];
    }
    lazy[i] = 0;
}
void upd(int i, int l, int r, int L, int R, int x) {
    if(r < L || R < l) return;
    if(L <= l && r <= R) {
        lazy[i] += x;
        return;
    }
    int m = (l + r) / 2;
    prop(i, l, r);
    upd(2 * i + 1, l, m, L, R, x);
    upd(2 * i + 2, m + 1, r, L, R, x);
    tree[i] = min(get(2 * i + 1), get(2 * i + 2));
}
int query(int i, int l, int r) {
    if(get(i) >= 0) return -1;
    if(l == r && get(i) < 0) return l;
    prop(i, l, r);
    int m = (l + r) / 2;
    int ans = query(2 * i + 2, m + 1, r);
    if(ans != -1) return ans;
    return query(2 * i + 1, l, m);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vi amt(N + 1, 0);
    vi a(n + 1), b(m + 1);
    rep(i, 1, n + 1) {
        cin >> a[i];
        amt[a[i]]--;
    }
    rep(i, 1, m + 1) {
        cin >> b[i];
        amt[b[i]]++;
    }
    for(int i = N - 1; i >= 1; i--) {
        amt[i] += amt[i + 1];
    }
    build(0, 1, N, amt);
    int q; cin >> q;
    while(q--) {
        int ty, i, x;
        cin >> ty >> i >> x;
        if(ty == 1) {
            upd(0, 1, N, 1, a[i], +1);
            a[i] = x;
            upd(0, 1, N, 1, a[i], -1);
        }else {
            upd(0, 1, N, 1, b[i], -1);
            b[i] = x;
            upd(0, 1, N, 1, b[i], +1);
        }
        cout << query(0, 1, N) << '\n';
    }
}