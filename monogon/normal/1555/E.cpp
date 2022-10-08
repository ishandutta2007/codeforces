
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
int tree[4 * N], lz[4 * N];

int get(int i) {
    return tree[i] + lz[i];
}
void prop(int i, int l, int r) {
    if(lz[i] == 0) return;
    tree[i] += lz[i];
    if(l != r) {
        lz[2 * i + 1] += lz[i];
        lz[2 * i + 2] += lz[i];
    }
    lz[i] = 0;
}
void upd(int i, int l, int r, int L, int R, int x) {
    if(r < L || R < l) return;
    if(L <= l && r <= R) {
        lz[i] += x;
        return;
    }
    int m = (l + r) / 2;
    upd(2 * i + 1, l, m, L, R, x);
    upd(2 * i + 2, m + 1, r, L, R, x);
    tree[i] = min(get(2 * i + 1), get(2 * i + 2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> seg;
    rep(i, 0, n) {
        int l, r, w;
        cin >> l >> r >> w;
        seg.push_back({w, l, r});
    }
    sort(all(seg));
    int j = 0, ans = INT_MAX;
    rep(i, 0, sz(seg)) {
        while(j < sz(seg) && get(0) == 0) {
            upd(0, 1, m - 1, seg[j][1], seg[j][2] - 1, 1);
            j++;
        }
        if(get(0) != 0) ans = min(ans, seg[j - 1][0] - seg[i][0]);
        upd(0, 1, m - 1, seg[i][1], seg[i][2] - 1, -1);
    }
    cout << ans << '\n';
}