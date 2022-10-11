#ifndef LOCAL
    #pragma GCC optimize("Ofast,O3")
#endif

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

const int B = 2500;

struct update {
    int pos, to;
};

struct query {
    int l, r, when, id;

    bool operator<(const query &q) const {
        return ar<int, 3>{l / B, r / B, when} < ar<int, 3>{q.l / B, q.r / B, q.when};
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vec<int> a(n), va(n);
    iota(all(va), 0);
    vec<set<int>> where(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i], a[i]--;
        where[a[i]].insert(i);
    }
    vec<int> l(n), r(n);
    auto get_left = [&](int x, int pos) {
        auto it = where[x].lower_bound(pos);
        if (it == where[x].begin()) return -1;
        return *prev(it);
    };
    auto get_right = [&](int x, int pos) {
        auto it = where[x].upper_bound(pos);
        if (it == where[x].end()) return n;
        return *it;
    };
    for (int i = 0; i < n; i++) {
        l[i] = get_left(a[i], i);
        r[i] = get_right(a[i], i);
    }
    int cur_ver = n;
    vec<update> updates;
    vec<query> queries;
    l.reserve(n + 5 * q);
    r.reserve(n + 5 * q);
    updates.reserve(n + 5 * q);
    queries.reserve(q);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos, x;
            cin >> pos >> x, pos--, x--;
            if (a[pos] == x) continue;
            {
                int prev_before = l[va[pos]];
                int next_before = r[va[pos]];
                if (prev_before != -1) {
                    updates.push_back({prev_before, cur_ver});
                    l.push_back(l[va[prev_before]]);
                    r.push_back(next_before);
                    va[prev_before] = cur_ver++;
                }
                if (next_before != n) {
                    updates.push_back({next_before, cur_ver});
                    l.push_back(prev_before);
                    r.push_back(r[va[next_before]]);
                    va[next_before] = cur_ver++;
                }
                where[a[pos]].erase(pos);
                a[pos] = x;
                where[a[pos]].insert(pos);
            }
            {
                int prev_after = get_left(a[pos], pos);
                int next_after = get_right(a[pos], pos);
                updates.push_back({pos, cur_ver});
                l.push_back(prev_after);
                r.push_back(next_after);
                va[pos] = cur_ver++;
                if (prev_after != -1) {
                    updates.push_back({prev_after, cur_ver});
                    l.push_back(l[va[prev_after]]);
                    r.push_back(pos);
                    va[prev_after] = cur_ver++;
                }
                if (next_after != n) {
                    updates.push_back({next_after, cur_ver});
                    l.push_back(pos);
                    r.push_back(r[va[next_after]]);
                    va[next_after] = cur_ver++;
                }
            }
        } else {
            int l, r;
            cin >> l >> r, l--;
            queries.push_back({l, r, len(updates) - 1, len(queries)});
        }
    }
    iota(all(va), 0);
    sort(all(queries));
    int cur_l = 0, cur_r = 0, cur_time = -1;
    ll cur_ans = 0;
    vec<ll> ans(len(queries));
    for (auto [tl, tr, when, id] : queries) {
        for (; cur_r < tr; cur_r++) {
            if (l[va[cur_r]] >= cur_l) cur_ans += cur_r - l[va[cur_r]];
        }
        for (; cur_l > tl; cur_l--) {
            if (r[va[cur_l - 1]] < cur_r) cur_ans += r[va[cur_l - 1]] - (cur_l - 1);
        }
        for (; cur_r > tr; cur_r--) {
            if (l[va[cur_r - 1]] >= cur_l) cur_ans -= (cur_r - 1) - l[va[cur_r - 1]];
        }
        for (; cur_l < tl; cur_l++) {
            if (r[va[cur_l]] < cur_r) cur_ans -= r[va[cur_l]] - cur_l;
        }
        auto relax = [&](int pos, int p) {
            if (l[va[pos]] >= cur_l) cur_ans += p * (pos - l[va[pos]]);
        };
        auto update_pos = [&](int pos, int &to) {
            if (cur_l <= pos && pos < cur_r) relax(pos, -1);
            swap(to, va[pos]);
            if (cur_l <= pos && pos < cur_r) relax(pos, 1);
        };
        for (; cur_time > when; cur_time--) {
            auto &[pos, to] = updates[cur_time];
            update_pos(pos, to);
        }
        for (; cur_time < when; cur_time++) {
            auto &[pos, to] = updates[cur_time + 1];
            update_pos(pos, to);
        }
        ans[id] = cur_ans;
    }
    for (auto x : ans) {
        cout << x << '\n';
    }
}