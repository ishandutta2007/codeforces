#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, q;
const int maxN = 4e5 + 10;
int fenw_cnt[maxN];
ll fenw_sum[maxN];
void upd(int v, ll val, int d) {
    while (v < maxN) {
        fenw_cnt[v] += d;
        fenw_sum[v] += val * d;
        v = (v | (v - 1)) + 1;
    }
}
ll getSum(int i) {
    i++;
    ll cur_sum = 0;
    int pos = 0;
    for (int k = 19; k >= 0; k--) {
        if (pos + (1 << k) < maxN && fenw_cnt[pos + (1 << k)] < i) {
            cur_sum += fenw_sum[pos + (1 << k)];
            i -= fenw_cnt[pos + (1 << k)];
            pos += (1 << k);
        }
    }
    return cur_sum;
}
struct node{
    ll sum, sum_mult, sz;
    node() : sum(0), sum_mult(0), sz(0) {}
};
node t[4 * maxN];
node merge(const node& a, const node& b) {
    node c;
    c.sz = a.sz + b.sz;
    c.sum = a.sum + b.sum;
    c.sum_mult = a.sum_mult + b.sum_mult + b.sum * a.sz;
    return c;
}
void ch(int v, int tl, int tr, int pos, ll val, int d) {
    if (tl == tr) {
        t[v].sz += d;
        t[v].sum += d * val;
        t[v].sum_mult = 0;
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) ch(2 * v, tl, tm, pos, val, d);
    else ch(2 * v + 1, tm + 1, tr, pos, val, d);
    t[v] = merge(t[2 * v], t[2 * v + 1]);
}
node get(int v, int tl, int tr, int lim_sz) {
    if (lim_sz == 0) {
        return node();
    }
    if (lim_sz >= t[v].sz) return t[v];
    int tm = (tl + tr) / 2;
    node p1 = get(2 * v, tl, tm, lim_sz);
    lim_sz -= p1.sz;
    node p2 = get(2 * v + 1, tm + 1, tr, lim_sz);
    return merge(p1, p2);
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    vector<ll> all;
    vector<ll> cord;
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        cord.emplace_back(x);
        all.emplace_back(x);
    }
    for (int i = 0; i < q; i++) {
        int tp;
        ll a;
        cin >> tp >> a;
        cord.emplace_back(a);
        if (tp == 1) all.emplace_back(a);
        else all.emplace_back(~a);
    }
    sort(cord.begin(), cord.end());
    cord.erase(unique(cord.begin(), cord.end()), cord.end());
    ll S = 0;
    for (int i = 0; i < n; i++) {
        int id = lower_bound(cord.begin(), cord.end(), all[i]) - cord.begin() + 1;
        upd(id, all[i], +1);
        ch(1, 1, cord.size(), id, all[i], +1);
        S += all[i];
    }
    auto get_sum_pref = [&](int from, int to) {
        node c = get(1, 1, cord.size(), to);
        ll s = c.sum * c.sz - c.sum_mult;
        if (from > 1) {
            c = get(1, 1, cord.size(), from - 1);
            s -= (c.sum * c.sz - c.sum_mult);
        }
        return s;
    };
    auto compute = [&]() -> ll{
        if (n == 0) return 0;
        int L = 1;
        int R = (n + 1) / 2 + 1;
        while (R - L > 1) {
            int mid = (L + R) / 2;
            ll p1 = getSum(mid);
            ll p2 = getSum(n + 1 - mid);
            if (p1 + p2 >= S) L = mid;
            else R = mid;
        }
        ll F = get_sum_pref(1, L) + get_sum_pref(n + 1 - L, n) - L * S;
        F *= 2;
        if (L == (n + 1) / 2 && n % 2 == 1) {
            F -= (2 * getSum((n + 1) / 2) - S);
        }
        return S - F;
    };
    int from = n;
    int to = n + q;
    cout << compute() << '\n';
    for (int i = from; i < to; i++) {
        if (all[i] > 0) {
            int id = lower_bound(cord.begin(), cord.end(), all[i]) - cord.begin() + 1;
            ch(1, 1, cord.size(), id, all[i], +1);
            upd(id, all[i], +1);
            S += all[i];
            n++;
        }
        else {
            all[i] = ~all[i];
            int id = lower_bound(cord.begin(), cord.end(), all[i]) - cord.begin() + 1;
            ch(1, 1, cord.size(), id, all[i], -1);
            upd(id, all[i], -1);
            S -= all[i];
            n--;
        }
        cout << compute() << '\n';
    }

}