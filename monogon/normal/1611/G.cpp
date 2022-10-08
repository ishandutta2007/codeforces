
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

const int N = 2e6 + 5;
int tree[4 * N];

void build(int i, int l, int r) {
    tree[i] = 0;
    if(l == r) return;
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
}
int query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return 0;
    if(L <= l && r <= R) return tree[i];
    int m = (l + r) / 2;
    return max(query(2 * i + 1, l, m, L, R), query(2 * i + 2, m + 1, r, L, R));
}
void upd(int i, int l, int r, int k, int x) {
    if(l == r) {
        tree[i] = max(tree[i], x);
        return;
    }
    int m = (l + r) / 2;
    if(k <= m) upd(2 * i + 1, l, m, k, x);
    else upd(2 * i + 2, m + 1, r, k, x);
    tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    vector<pii> A[2];
    rep(i, 0, n) {
        cin >> s[i];
        rep(j, 0, m) {
            if(s[i][j] == '1') {
                A[(i + j) % 2].push_back({i - j, i + j});
            }
        }
    }
    int ans = 0;
    rep(b, 0, 2) {
        build(0, 0, n + m + 1);
        vector<pii> &ve = A[b];
        // find longest decreasing subsequence
        sort(all(ve));
        for(auto &pa : ve) {
            int mx = query(0, 0, n + m, pa.second + 1, n + m + 1);
            upd(0, 0, n + m, pa.second, mx + 1);
        }
        ans += query(0, 0, n + m, 0, n + m);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}