#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()
#define time time228

const int B = 2048;
const int N = 2e5 + 4;
const int INF = 1e9;

struct query {
    int l, r, k;
    int time, id;

    query() {}
    query(int l, int r, int k, int time, int id) : l(l), r(r), k(k), time(time), id(id) {}

    inline bool operator < (query q) {
        if (l / B != q.l / B)
            return l / B < q.l / B;
        if (r / B != q.r / B)
            return r / B < q.r / B;
        return (time < q.time) ^ ((r / B) & 1);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vec<int> a(n);
    for (auto &x : a)
        cin >> x;

    vec<int> cnt(N);
    cnt[0] = N;
    vec<int> l(N, N), r(N, N - 1);
    l[0] = 0;
    r[0] = N - 1;
    vec<int> nxt(N, -1);
    vec<int> prev(N, -1);

    vec<pr<int, int>> changes;
    vec<query> queries;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            l--, r--;
            queries.push_back(query(l, r, k, len(changes) - 1, i - len(changes)));
        } else {
            int p, x;
            cin >> p >> x;
            p--;
            changes.emplace_back(p, x);
        }
    }
    sort(all(queries));

    auto insert = [&](int x) {
        int cur = cnt[x]++;
        r[cur]--;
        l[cur + 1]--;
        if (l[cur] > r[cur]) {
            if (prev[cur] != -1)
                nxt[prev[cur]] = cur + 1;
            prev[cur + 1] = prev[cur];
        }
        if (l[cur + 1] == r[cur + 1]) {
            if (nxt[cur] != -1)
                prev[nxt[cur]] = cur + 1;
            nxt[cur + 1] = nxt[cur];
            nxt[cur] = cur + 1;
            if (l[cur] <= r[cur])
                prev[cur + 1] = cur;
        }
    };

    auto erase = [&](int x) {
        int cur = cnt[x]--;
        l[cur]++;
        r[cur - 1]++;
        if (l[cur] > r[cur]) {
            nxt[cur - 1] = nxt[cur];
            if (nxt[cur] != -1)
                prev[nxt[cur]] = cur - 1;
        }
        if (l[cur - 1] == r[cur - 1]) {
            if (prev[cur] != -1)
                nxt[prev[cur]] = cur - 1;
            prev[cur - 1] = prev[cur];
            prev[cur] = cur - 1;
            if (l[cur] <= r[cur])
                nxt[cur - 1] = cur;
        }
    };

    auto get_len = [&](int x) {
        return r[x] - l[x] + 1;
    };

    int cur_l = 0, cur_r = -1, cur_t = -1;
    vec<int> ans(len(queries));
    for (auto [l, r, k, time, id] : queries) {
        while (cur_t < time) {
            auto &[p, val] = changes[++cur_t];
            if (cur_l <= p && p <= cur_r) {
                erase(a[p]);
                insert(val);
            }
            swap(val, a[p]);
        }
        while (cur_t > time) {
            auto &[p, val] = changes[cur_t--];
            if (cur_l <= p && p <= cur_r) {
                erase(a[p]);
                insert(val);
            }
            swap(val, a[p]);
        }
        while (cur_r < r)
            insert(a[++cur_r]);
        while (cur_l > l)
            insert(a[--cur_l]);
        while (cur_r > r)
            erase(a[cur_r--]);
        while (cur_l < l)
            erase(a[cur_l++]);

        int res = INF;
        int j = 0;
        int need = 0;
        for (int cur = nxt[0]; cur != -1; cur = nxt[cur]) {
            if (j < cur) {
                j = cur;
                need = k - get_len(cur);
            } else if (prev[cur] != -1)
                need += get_len(prev[cur]);
            while (j != -1 && need > 0) {
                j = nxt[j];
                if (j != -1)
                    need -= get_len(j);
            }
            if (j == -1)
                break;
            if (res > j - cur)
                res = j - cur;
        }
        if (res == INF)
            ans[id] = -1;
        else
            ans[id] = res;
    }

    for (auto x : ans)
        cout << x << '\n';
}