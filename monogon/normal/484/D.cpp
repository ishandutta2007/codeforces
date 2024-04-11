
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

// dp[i] = max_{j < i} |a[i] - a[j]| + dp[j - 1]
// maintain, max sum with a next child k
// max sum with no next child

const int N = 2e6 + 5;

ll tree[4 * N];

void build(int i, int l, int r) {
    if(l == r) {
        tree[i] = LLONG_MIN;
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
}

ll query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return LLONG_MIN;
    if(L <= l && r <= R) return tree[i];
    int m = (l + r) / 2;
    return max(query(2 * i + 1, l, m, L, R), query(2 * i + 2, m + 1, r, L, R));
}
void upd(int i, int l, int r, int k, ll x) {
    if(l == r) {
        tree[i] = max(tree[i], x);
        return;
    }
    int m = (l + r) / 2;
    if(k <= m) upd(2 * i + 1, l, m, k, x);
    else upd(2 * i + 2, m + 1, r, k, x);
    tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n + 1), val;
    rep(i, 1, n + 1) {
        cin >> a[i];
        val.push_back(a[i]);
    }
    sort(all(val));
    val.erase(unique(all(val)), val.end());
    build(0, 0, 2 * n - 1);
    ll mx = 0;
    rep(i, 1, n + 1) {
        int pos = lower_bound(all(val), a[i]) - val.begin();
        ll newmx = mx;
        ll qu = query(0, 0, 2 * n - 1, pos, n - 1);
        if(qu != LLONG_MIN) newmx = max(newmx, qu - a[i]);
        qu = query(0, 0, 2 * n - 1, n, n + pos);
        if(qu != LLONG_MIN) newmx = max(newmx, qu + a[i]);
        upd(0, 0, 2 * n - 1, pos, mx + a[i]);
        upd(0, 0, 2 * n - 1, n + pos, mx - a[i]);
        mx = newmx;
    }
    cout << mx << '\n';
}