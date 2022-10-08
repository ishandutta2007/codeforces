
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
    int sum, mx, mn;
    node(int val = 0) {
        sum = val;
        mx = max(0, val);
        mn = min(0, val);
    }
    node(int sum, int mx, int mn) : sum(sum), mx(mx), mn(mn) {}
    node operator+(const node &o) const {
        return node(sum + o.sum, max(mx, sum + o.mx), min(mn, sum + o.mn));
    }
};

const int N = 2e5 + 5;
node tree[4 * N];

void build(int i, int l, int r, const string &s) {
    if(l == r) {
        tree[i] = node(s[l] == '+' ? 1 : -1);
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m, s);
    build(2 * i + 2, m + 1, r, s);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}
node query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return node(0);
    if(L <= l && r <= R) return tree[i];
    int m = (l + r) / 2;
    return query(2 * i + 1, l, m, L, R) + query(2 * i + 2, m + 1, r, L, R);
}

void solve() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    build(0, 0, n - 1, s);
    while(m--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        node A = query(0, 0, n - 1, 0, l - 1);
        node B = query(0, 0, n - 1, r + 1, n - 1);
        A = A + B;
        cout << (A.mx - A.mn + 1) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}