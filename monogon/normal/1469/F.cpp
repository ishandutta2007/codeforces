
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

const int N = 4e5 + 5;
ll tree[4 * N], lazy[4 * N];

void prop(int i, int l, int r) {
    if(lazy[i] == 0) return;
    tree[i] += lazy[i] * (r - l + 1);
    if(l < r) {
        lazy[2 * i + 1] += lazy[i];
        lazy[2 * i + 2] += lazy[i];
    }
    lazy[i] = 0;
}
ll get(int i, int l, int r) {
    return tree[i] + lazy[i] * (r - l + 1);
}
int query(int i, int l, int r, ll k) {
    if(l == r) return l;
    int m = (l + r) / 2;
    prop(i, l, r);
    ll val = get(2 * i + 1, l, m);
    if(val > k) return query(2 * i + 1, l, m, k);
    else return query(2 * i + 2, m + 1, r, k - val);
}
void upd(int i, int l, int r, int L, int R, ll x) {
    prop(i, l, r);
    if(r < L || R < l) return;
    if(L <= l && r <= R) {
        lazy[i] += x;
        prop(i, l, r);
        return;
    }
    int m = (l + r) / 2;
    upd(2 * i + 1, l, m, L, R, x);
    upd(2 * i + 2, m + 1, r, L, R, x);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}
// ll getsum(int i, int l, int r, int L, int R) {
//     if(r < L || R < l) return 0;
//     prop(i, l, r);
//     if(L <= l && r <= R) return tree[i];
//     int m = (l + r) / 2;
//     return getsum(2 * i + 1, l, m, L, R) + getsum(2 * i + 2, m + 1, r, L, R);
// }

// void printtree(ll w) {
//     cout << "-----" << endl;
//     // rep(i, 0, w) {
//     //     cout << query(0, 0, N - 1, i) << ' ';
//     // }
//     // cout << endl;
//     rep(i, 0, 10) {
//         cout << getsum(0, 0, N - 1, i, i) << ' ';
//     }
//     cout << endl;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll k;
    cin >> n >> k;
    vi l(n);
    ll sum = 0;
    rep(i, 0, n) {
        cin >> l[i];
        sum += l[i];
    }
    sort(l.rbegin(), l.rend());
    if(1 + sum - 2 * n < k) {
        cout << -1 << '\n';
        return 0;
    }
    upd(0, 0, N - 1, 0, 0, 1);
    ll w = 1;
    int ans = 1e9;
    rep(i, 0, n) {
        // printtree(w);
        if(w >= k) {
            ans = min(ans, query(0, 0, N - 1, k - 1));
        }
        int pos = query(0, 0, N - 1, 0);
        upd(0, 0, N - 1, pos, pos, -1);
        upd(0, 0, N - 1, pos + 2, pos + 1 + l[i] / 2, 2);
        if(l[i] % 2 == 0) upd(0, 0, N - 1, pos + 1 + l[i] / 2, pos + 1 + l[i] / 2, -1);
        w += l[i] - 2;
    }
    assert(w >= k);
    ans = min(ans, query(0, 0, N - 1, k - 1));
    cout << ans << '\n';
}