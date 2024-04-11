#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxK = (int)1e6 + 10;
const int maxN = 3 * (int)1e5 + 10;
int a[maxN];
int n, k;
int pref[maxN];
vector < int > all[maxK];
pair < int, int > t[4 * maxN];
pair < int, int > get_mx(int v, int tl, int tr, int l, int r) {
    if (l == tl && r == tr) return t[v];
    int tm = (tl + tr) / 2;
    if (r <= tm) return get_mx(v + v, tl, tm, l, r);
    if (l > tm) return get_mx(v + v + 1, tm + 1, tr, l, r);
    pair < int, int > t1 = get_mx(v + v, tl, tm, l, tm);
    pair < int, int > t2 = get_mx(v + v + 1, tm + 1, tr, tm + 1, r);
    return max(t1, t2);
}
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_pair(a[tl], tl);
        return;
    }
    int tm = (tl + tr) / 2;
    build(v + v, tl, tm);
    build(v + v + 1, tm + 1, tr);
    t[v] = max(t[v + v], t[v + v + 1]);
}
int get_val(int l, int r, int val) {
    int x = lower_bound(all[val].begin(), all[val].end(), l) - all[val].begin();
    int y = upper_bound(all[val].begin(), all[val].end(), r) - all[val].begin();
    return y - x;
}
ll ans = 0;
void solve(int l, int r) {
    if (l > r) return;
    auto t = get_mx(1, 1, n, l, r);
    int ind = t.second;
    int val = t.first;
    // l - 1, .. ind - 1    ;;; ind, .. r
    int len1 = (ind - 1) - (l - 1) + 1;
    int len2 = (r - ind + 1);
    if (len1 <= len2) {
        for (int i = l - 1; i <= ind - 1; i++) {
            int need = (pref[i] + val) % k;
            ans += get_val(ind, r, need);
        }
    }
    else {
        for (int i = ind; i <= r; i++) {
            int need = ((pref[i] - val) % k + k) % k;
            ans += get_val(l - 1, ind - 1, need);
        }
    }
    solve(l, ind - 1);
    solve(ind + 1, r);
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    srand(time(0));
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = (pref[i - 1] + a[i]) % k;
    }
    for (int i = 0; i <= n; i++) {
        all[pref[i]].push_back(i);
    }
    build(1, 1, n);
    solve(1, n);
    cout << ans - n;
}