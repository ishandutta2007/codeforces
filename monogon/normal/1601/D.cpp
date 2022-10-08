
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
ll tree[4 * N];

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
    int n; ll d;
    cin >> n >> d;
    vector<ll> s(n), a(n);
    vector<ll> val;
    rep(i, 0, n) {
        cin >> s[i] >> a[i];
        val.push_back(s[i]);
        val.push_back(a[i]);
    }
    sort(all(val));
    val.erase(unique(all(val)), val.end());
    auto get = [&](ll x) {
        return lower_bound(all(val), x) - val.begin();
    };
    int cnt = 0;
    vector<array<ll, 3>> ve;
    rep(i, 0, n) {
        if(s[i] >= d) {
            s[i] = get(s[i]);
            a[i] = get(a[i]);
            if(s[i] <= a[i]) {
                ve.push_back({a[i], s[i], i});
            }else {
                ve.push_back({s[i], a[i], i});
                cnt++;
            }
        }
    }
    sort(all(ve));

    ll mx = sz(val);
    ll mn = LLONG_MIN;
    for(auto &pa : ve) {
        ll r = pa[0], l = pa[1], i = pa[2];
        if(s[i] <= a[i]) {
            if(l >= mn) {
                ll len = query(0, 0, mx, 0, l);
                upd(0, 0, mx, r, len + 1);
            }
        }else {
            mn = max(mn, l);
        }
    }
    cout << tree[0] + cnt << '\n';
}