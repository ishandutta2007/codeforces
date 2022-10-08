
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

const int N = 1 << 19;
int n, m, a[N], x, val[N], tree[4 * N];

void build(int i, int l, int r) {
    if(l == r) {
        tree[i] = val[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}

int query(int i, int l, int r) {
    if(l == r) {
        return l;
    }
    int m = (l + r) / 2;
    int bit = (r - l + 1) & -(r - l + 1);
    if(x & (bit / 2)) {
        if(tree[2 * i + 2] == r - (m + 1) + 1) {
            return query(2 * i + 1, l, m);
        }else {
            return query(2 * i + 2, m + 1, r);
        }
    }else {
        if(tree[2 * i + 1] == m - l + 1) {
            return query(2 * i + 2, m + 1, r);
        }else {
            return query(2 * i + 1, l, m);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> a[i];
        val[a[i]] = 1;
    }
    build(0, 0, N - 1);
    rep(i, 0, m) {
        int xx;
        cin >> xx;
        x ^= xx;
        cout << (x ^ query(0, 0, N - 1)) << '\n';
    }
}