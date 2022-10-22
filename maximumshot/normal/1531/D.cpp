#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

struct RangeTree {
    int n = 0; // [0, n)
    vector<int> pu, f;

    RangeTree() = default;

    RangeTree(int n_) {
        n = n_;
        f.resize(4 * n, 1);
        pu.resize(4 * n, -1);
    }

    void upd(int v, int x) {
        pu[v] = x;
        f[v] = x;
    }

    void push(int v) {
        if (pu[v] != -1) {
            upd(v << 1, pu[v]);
            upd(v << 1 | 1, pu[v]);
            pu[v] = -1;
        }
    }

    void merge(int v) {
        f[v] = f[v << 1] | f[v << 1 | 1];
    }

    void update(int v, int tl, int tr, int l, int r, int x) {
        if (l <= tl && tr <= r) {
            upd(v, x);
        } else {
            int tm = (tl + tr) >> 1;
            push(v);
            if (l <= tm)
                update(v << 1, tl, tm, l, r, x);
            if (r > tm)
                update(v << 1 | 1, tm + 1, tr, l, r, x);
            merge(v);
        }
    }

    void update(int l, int r, int x) {
        update(1, 0, n - 1, l, r, x);
    }

    int query(int v, int tl, int tr) {
        if (tl == tr) {
            return tl;
        } else {
            int tm = (tl + tr) >> 1, res = -1;
            push(v);
            if (f[v << 1 | 1])
                res = query(v << 1 | 1, tm + 1, tr);
            else
                res = query(v << 1, tl, tm);
            merge(v);
            return res;
        }
    }

    int query() {
        return query(1, 0, n - 1);
    }
};

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> s(n + 1);
    s[0] = "blue";
    for (int i = 1; i <= n; i++)
        cin >> s[i];

    set<int> q;
    RangeTree rt(n + 1);

    auto apply = [&](set<int>::iterator it) {
        int l = *it;
        it++;
        int r = it == q.end() ? n : *it - 1;
        int x = s[l] == "lock" ? 0 : 1;
        rt.update(l, r, x);
        rt.update(l, l, 0);
    };

    auto query = [&]() -> int {
        return rt.query();
    };

    auto check = [&](const string& ss) -> bool {
        return ss == "lock" || ss == "unlock";
    };

    for (int i = 0; i <= n; i++) {
        if (check(s[i]))
            q.insert(i);
    }

    for (auto it = q.begin(); it != q.end(); it++)
        apply(it);

    int t;
    cin >> t;

    cout << s[query()] << "\n";

    while (t--) {
        int pos;
        string value;
        cin >> pos >> value;
        if (check(s[pos])) {
            auto it = q.lower_bound(pos);
            it = q.erase(it);
            if (it != q.begin()) {
                it--;
                apply(it);
            } else {
                int r = it == q.end() ? n : *it - 1;
                rt.update(0, r, 1);
            }
        }
        s[pos] = value;
        if (check(s[pos])) {
            q.insert(pos);
            auto it = q.lower_bound(pos);
            apply(it);
        }
        cout << s[query()] << "\n";
    }

    return 0;
}