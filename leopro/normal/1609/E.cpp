#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

struct state {
    int a, b, c, ab, bc, abc;

    state(int a, int b, int c, int ab, int bc, int abc) : a(a), b(b), c(c), ab(ab), bc(bc), abc(abc) {}

    static state merge(state p, state q) {
        return state(p.a + q.a, p.b + q.b, p.c + q.c, min({p.ab + q.b, p.a + q.ab}), min({p.bc + q.c, p.b + q.bc}),
                     min({p.abc + q.c, p.a + q.abc, p.ab + q.bc}));
    }

    state() : a(0), b(0), c(0), ab(0), bc(0), abc(0) {}

    static state sa() { return {1, 0, 0, 0, 0, 0}; }

    static state sb() { return {0, 1, 0, 0, 0, 0}; }

    static state sc() { return {0, 0, 1, 0, 0, 0}; }

    static void print(const state &s) {
        cerr << s.a << ' ' << s.b << ' ' << s.c << ' ' << s.ab << ' ' << s.bc << ' ' << s.abc << '\n';
    }
};

struct SegmentTree {
    int n;
    vector<state> states;

    explicit SegmentTree(int sz) : n(2 << __lg(sz - 1)), states(2 * n) {}

    void set(int i, char c) {
        i += n;
        if (c == 'a') states[i] = state::sa();
        if (c == 'b') states[i] = state::sb();
        if (c == 'c') states[i] = state::sc();
        for (i /= 2; i > 0; i /= 2) states[i] = state::merge(states[2 * i], states[2 * i + 1]);
    }

    int cost() { return states[1].abc; }
};

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    SegmentTree st(n);
    for (int i = 0; i < s.size(); ++i) st.set(i, s[i]);
    for (int j = 0; j < q; ++j) {
        int index;
        char c;
        cin >> index >> c;
        --index;
        st.set(index, c);
        cout << st.cost() << '\n';
    }
}