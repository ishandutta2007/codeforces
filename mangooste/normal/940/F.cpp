#include <bits/stdc++.h>

using namespace std;

const int K = 3300;

struct Change {
    int pos;
    int from;
    int to;

    Change(int pos = -1, int from = 0, int to = 0) :
        pos(pos), from(from), to(to)
    {}
};

struct Query {
    int l;
    int r;
    int timer;
    int index;

    Query(int l = 0, int r = 0, int timer = -1, int index = -1) :
        l(l), r(r), timer(timer), index(index)
    {}

    bool operator < (const Query &q) const {
        return array<int, 3>{l / K, r / K, timer} < array<int, 3>{q.l / K, q.r / K, q.timer};
    }
};

inline int compress(vector<Change> &changes, vector<int> &a) {
    vector<int> vals = a;
    for (auto [pos, from, to] : changes)
        vals.push_back(to);
    sort(vals.begin(), vals.end());
    vals.resize((int) (unique(vals.begin(), vals.end()) - vals.begin()));
    int mx = (int) vals.size();

    auto get = [&](int val) {
        return (int) (lower_bound(vals.begin(), vals.end(), val) - vals.begin());
    };
    for (auto &x : a)
        x = get(x);
    for (auto &[pos, from, to] : changes) {
        from = get(from);
        to = get(to);
    }
    return mx;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    vector<int> start_a = a;
    vector<Change> changes;
    vector<Query> queries;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            l--;
            int index = (int) queries.size();
            queries.push_back(Query(l, r, (int) changes.size(), index));
        } else {
            int pos, new_val;
            cin >> pos >> new_val;
            pos--;
            changes.push_back(Change(pos, a[pos], new_val));
            a[pos] = new_val;
        }
    }
    a = start_a;

    int mx = compress(changes, a);

    int cur_time = 0;
    int l = 0, r = 0;

    vector<int> num(mx, 0);
    vector<int> cnt_num(n + 2, 0);

    auto insert = [&](int x) {
        cnt_num[num[x]]--;
        num[x]++;
        cnt_num[num[x]]++;
    };
    auto erase = [&](int x) {
        cnt_num[num[x]]--;
        num[x]--;
        cnt_num[num[x]]++;
    };

    auto change = [&](Change c) {
        if (l <= c.pos && c.pos < r)
            erase(c.from);
        a[c.pos] = c.to;
        if (l <= c.pos && c.pos < r)
            insert(c.to);        
    };
    auto rev_change = [&](Change c) {
        swap(c.from, c.to);
        change(c);
    };

    sort(queries.begin(), queries.end());
    vector<int> ans(queries.size());
    for (auto [need_l, need_r, timer, index] : queries) {
        while (cur_time < timer)
            change(changes[cur_time++]);
        while (cur_time > timer)
            rev_change(changes[--cur_time]);
        while (l > need_l)
            insert(a[--l]);
        while (r < need_r)
            insert(a[r++]);
        while (l < need_l)
            erase(a[l++]);
        while (r > need_r)
            erase(a[--r]);

        int &now = ans[index];
        now = 1;
        while (cnt_num[now] != 0)
            now++;
    }

    for (auto x : ans)
        cout << x << '\n';
}