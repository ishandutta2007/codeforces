#include<bits/stdc++.h>
using namespace std;
int const nax = 4e5 + 10;
const int64_t INF = 1e17;

struct op {
    char s[4];
    int x, y;
};

istream& operator >>(istream &in, op &my_op) {
    auto &[s, x, y] = my_op;
    in >> s;
    if (s[0] == 's') {
        in >> x >> y;
    } else if (s[0] == 'i') {
        in >> x;
    }
    return in;
}

struct dp {
    map <int, int64_t> val;
    set <pair <int64_t, int>> by_val;
    int64_t add = 0;

    void set_val(int key, int64_t new_val) {
        int64_t old_val = get_val(key);
        if (new_val < old_val) {
            if (old_val != INF) by_val.erase(make_pair(old_val - add, key));
            by_val.emplace(new_val - add, key);
            val[key] = new_val - add;
        }
    }

    int64_t get_val(int key) {
        if (!val.count(key)) return INF;
        return val[key] + add;
    }

    int64_t get_min() {
        assert(!by_val.empty());
        if (by_val.empty()) return INF;
        return by_val.begin()->first + add;
    }

    void del(int key) {
        if (!val.count(key)) return;
        by_val.erase(make_pair(val[key], key));
        val.erase(key);
    }

    /**
        what do we need to store?
        dp(x) -> minimum value to finish and have current X = x
        now keep this in std::map
    */
};

using ptr = std::shared_ptr<dp>;

int match[nax];
int n, forbid;
op a[nax];

ptr merge(ptr x, ptr y) {
    if (x->val.size() < y->val.size()) swap(x, y);
    for (auto &[key, value] : y->val) {
        x->set_val(key, value + y->add);
    }
    return x;
}

ptr solve(int l, int r, ptr x) {
    while (l <= r) {
        if (a[l].s[0] == 's') {
            int64_t min_val = x->get_min();
            int key = a[l].x;
            int cost = a[l].y;
            x->add += cost;
            if (key != forbid)
                x->set_val(key, min_val);
            ++ l;
        } else if (a[l].s[0] == 'i') {
            int block_key = a[l].x;
            int64_t dp_val = x->get_val(block_key);
            if (dp_val == INF) {
                l = match[l] + 1;
                continue;
            }

            x->del(block_key);
            ptr y(new dp());
            y->set_val(block_key, dp_val);
            y = solve(l + 1, match[l], y);
            x = merge(x, y);
            l = match[l] + 1;
        } else {
            l += 1;
        }
    }

    return x;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> forbid;
    vector <int> st;

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        if (a[i].s[0] == 'i') {
            st.push_back(i);
        } else if (a[i].s[0] == 'e') {
            match[st.back()] = i;
            st.pop_back();
        }
    }

    ptr x(new dp());
    x->set_val(0, 0);
    cout << (solve(1, n, x)->get_min());
}