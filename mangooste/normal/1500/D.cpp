#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

int q;
vec<int> used;
int timer;

inline void merge(vec<pr<int>> &a, vec<pr<int>> &b, vec<pr<int>> &res) {
    timer++;
    int j = 0;
    auto insert = [&](pr<int> p) {
        if (used[p.first] == timer)
            return;
        used[p.first] = timer;
        res.push_back(p);
    };
    for (int i = 0; i < len(a); i++) {
        while (len(res) <= q && j < len(b) && b[j].second >= a[i].second) {
            insert(b[j]);
            j++;
        }
        if (len(res) <= q)
            insert(a[i]);
        else
            break;
    }
    while (len(res) <= q && j < len(b)) {
        insert(b[j]);
        j++;
    }
}

struct my_stack {
    vec<pr<vec<pr<int>>>> st;

    my_stack() {}

    inline void pop_back() {
        assert(len(st));
        st.pop_back();
    }

    inline void push_back(vec<pr<int>> &a) {
        if (!len(st)) {
            st.emplace_back(a, a);
            return;
        }
        st.emplace_back(vec<pr<int>>{}, a);
        merge(st.end()[-2].first, a, st.back().first);
    }

    inline void rev() {
        assert(len(st));
        reverse(all(st));
        st[0].first = st[0].second;
        for (int i = 1; i < len(st); i++) {
            st[i].first.clear();
            merge(st[i].second, st[i - 1].first, st[i].first);
        }
    }

    inline int get_min() {
        assert(len(st));
        if (len(st.back().first) <= q)
            return -1;
        return st.back().first.back().second;
    }
};

struct my_queue {
    my_stack front, back;

    my_queue() {}

    inline void pop() {
        if (!len(front.st)) {
            swap(front, back);
            front.rev();
        }
        front.pop_back();
    }

    inline void push(vec<pr<int>> &a) {
        back.push_back(a);
    }

    inline int get_min() {
        assert(len(front.st) + len(back.st));
        if (!len(front.st))
            return back.get_min();
        if (!len(back.st))
            return front.get_min();
        vec<pr<int>> cur;
        merge(front.st.back().first, back.st.back().first, cur);
        if (len(cur) <= q)
            return -1;
        return cur.back().second;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n >> q;
    vec<vec<int>> a(n, vec<int>(n));
    for (auto &xs : a)
        for (auto &x : xs)
            cin >> x;

    vec<vec<pr<int>>> left(n);
    used.resize(n * n + 1);
    vec<int> ans(n);
    for (int j = 0; j < n; j++) {
        my_queue que;
        int prev = 0;
        for (int i = 0; i < n; i++) {
            vec<pr<int>> nleft{{a[i][j], j}};
            for (auto [x, pos] : left[i])
                if (x != a[i][j] && len(nleft) <= q)
                    nleft.emplace_back(x, pos);
            left[i] = nleft;

            que.push(left[i]);
            while (que.get_min() >= j - (i - prev)) {
                que.pop();
                prev++;
            }
            ans[i - prev]++;
        }
    }

    for (int i = n - 2; i >= 0; i--)
        ans[i] += ans[i + 1];
    for (auto x : ans)
        cout << x << '\n';
}