#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

struct Node {
    int l_any;
    int l_up;
    int l_down;
    int r_any;
    int r_up;
    int r_down;
    int ans;
    int len;

    Node(int l_any = 0, int l_up = 0, int l_down = 0, int r_any = 0, int r_up = 0, 
            int r_down = 0, int ans = 0, int len = 0):
        l_any(l_any), l_up(l_up), l_down(l_down), r_any(r_any), r_up(r_up), r_down(r_down), ans(ans), len(len) {}
};

Node unite(const Node& L, const Node& R) {
    Node res(L.l_any, L.l_up, L.l_down, R.r_any, R.r_up, R.r_down, max(L.ans, R.ans), L.len + R.len);

    if (L.l_up == L.len)
        res.l_any = max(res.l_any, L.l_up + R.l_any);
    if (L.l_any == L.len)
        res.l_any = max(res.l_any, L.l_any + R.l_down);
    if (L.l_up == L.len)
        res.l_up = max(res.l_up, L.l_up + R.l_up);
    if (L.l_down == L.len)
        res.l_down = max(res.l_down, L.l_down + R.l_down);

    if (R.r_up == R.len)
        res.r_any = max(res.r_any, R.r_up + L.r_any);
    if (R.r_any == R.len)
        res.r_any = max(res.r_any, R.r_any + L.r_down);
    if (R.r_up == R.len)
        res.r_up = max(res.r_up, R.r_up + L.r_up);
    if (R.r_down == R.len)
        res.r_down = max(res.r_down, R.r_down + L.r_down);

    res.ans = max(res.ans, res.l_any);
    res.ans = max(res.ans, res.r_any);
    res.ans = max(res.ans, L.r_any + R.l_down);
    res.ans = max(res.ans, L.r_down + R.l_any);

    return res; 
} 

vector<ll> diff;

Node for_diff(ll d) {
    Node res(0, 0, 0, 0, 0, 0, 0, 1);
    if (d == 0)
        return res;
    if (d > 0) {
        res.l_any = res.r_any = 1;
        res.ans = 1;
        res.l_up = 1;
        res.r_down = 1;
        return res;
    }
    res.l_any = res.r_any = 1;
    res.ans = 1;
    res.l_down = 1;
    res.r_up = 1;
    return res; 
}

const int N = 300 * 1000 * 4 + 100;

Node tree[N];

void build(int i, int l, int r) {
    if (l == r) {
        tree[i] = for_diff(diff[l]);
        return;    
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i] = unite(tree[2 * i + 1], tree[2 * i + 2]);
}

void rebuild(int i, int tl, int tr, int pos) {
    if (tl == tr) {
        tree[i] = for_diff(diff[tl]);
        return;
    }
    int m = (tl + tr) / 2;
    if (pos <= m)
        rebuild(2 * i + 1, tl, m, pos);
    else
        rebuild(2 * i + 2, m + 1, tr, pos);
    tree[i] = unite(tree[2 * i + 1], tree[2 * i + 2]);
}


int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n == 1) {
        int foo;
        cin >> foo;
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int l, r, d;
            cin >> l >> r >> d;
            cout << 1 << "\n";
        }
        return 0;
    }
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    diff.resize(n - 1);
    for (int i = 0; i < n - 1; i++)
        diff[i] = a[i + 1] - a[i];
    build(0, 0, n - 1);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r;
        ll d;
        cin >> l >> r >> d;
        l--;
        r--;
        if (l != 0) {
            diff[l - 1] += d;
            rebuild(0, 0, n - 1, l - 1);
        }
        if (r != n - 1) {
            diff[r] -= d;
            rebuild(0, 0, n - 1, r);
        }    
        cout << tree[0].ans + 1 << "\n";
    } 
}