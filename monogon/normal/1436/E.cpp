
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

const int N = 1e5 + 5;
int n;
int tree[4 * N];

int query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return INT_MAX;
    if(L <= l && r <= R) return tree[i];
    int m = (l + r) / 2;
    return min(query(2 * i + 1, l, m, L, R), query(2 * i + 2, m + 1, r, L, R));
}

void upd(int i, int l, int r, int k, int x) {
    if(l == r) {
        tree[i] = x;
        return;
    }
    int m = (l + r) / 2;
    if(k <= m) upd(2 * i + 1, l, m, k, x);
    else upd(2 * i + 2, m + 1, r, k, x);
    tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
}

bool b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vi a;
    rep(i, 1, n + 2) a.push_back(i);
    rep(i, 0, n) {
        int v;
        cin >> v;
        if(v != 1) b[1] = true;
        a.push_back(v);
    }
    if(!b[1]) {
        cout << 1 << endl;
        return 0;
    }
    for(int i = n + 1; i >= 1; i--) a.push_back(i);
    int idx = 1;
    for(int x : a) {
        int k = query(0, 1, n + 1, x, x);
        if(idx > n + 1 && query(0, 1, n + 1, 1, x - 1) > k) {
            b[x] = true;
        }
        idx++;
        upd(0, 1, n + 1, x, idx);
    }
    rep(i, 1, n + 3) {
        if(!b[i]) {
            cout << i << '\n';
            return 0;
        }
    }
}