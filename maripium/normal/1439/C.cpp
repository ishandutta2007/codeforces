#include <bits/stdc++.h>

using namespace std;

struct ST {
    int N;
    vector<int> first;
    vector<int> last;
    vector<int> lazy;
    vector<int64_t> sum;
    ST(int N = 0) : N(N), first(N << 2), last(N << 2), lazy(N << 2), sum(N << 2) {
    }
    void pop(int v) {
        sum[v] = sum[v << 1] + sum[v << 1 | 1];
        first[v] = first[v << 1];
        last[v] = last[v << 1 | 1];
    }
    void init(int v, int l, int r, vector<int> &A) {
        if (l == r) {
            first[v] = A[l];
            last[v] = A[l];
            sum[v] = A[l];
            return;
        }
        int md = (l+r) >>1;
        init(v << 1, l, md, A);
        init(v << 1 | 1, md+1, r, A);
        pop(v);
    }
    void apply(int v, int l, int r, int lz) {
        lazy[v] = lz;
        last[v] = lz;
        first[v] = lz;
        sum[v] = int64_t(r-l+1)*lz;
    }
    void push(int v, int l, int r) {
        if (lazy[v]) {
            int md = (l+r)>>1;
            apply(v << 1, l, md, lazy[v]);
            apply(v << 1 | 1, md+1, r, lazy[v]);
            lazy[v] = 0;
        }
    }
    void modify(int v, int l, int r, int x, int y) {
        if (last[v] >= y) return;
        if (r <= x && first[v] <= y) {
            apply(v, l, r, y);
            return;
        }
        push(v, l, r);
        int md = (l+r)>>1;
        modify(v << 1, l, md, x, y);
        if (md+1 <= x) modify(v << 1 | 1, md+1, r, x, y);
        pop(v);
    }
    int walk0(int v, int l, int r, int x, int y) {
        if (r < x || last[v] > y) return N;
        if (l == r) return l;
        push(v, l, r);
        int md = (l+r)>>1;
        int ans = walk0(v << 1, l, md, x, y);
        if (ans == N) ans = walk0(v << 1 | 1, md+1, r, x, y);
        return ans;
    }
    void walk1(int v, int l, int r, int x, int &y, int &diff, bool &die) {
        // cerr << v << ' ' << l << ' ' << r << ' ' << x << ' ' << y << '\n';
        if (r < x) return;
        if (die) return;
        if (l >= x && y < first[v]) {
            die = true;
            return;
        }
        if (l >= x && y >= sum[v]) {
            diff += r-l+1;
            y -= sum[v];
            return;
        }
        int md = (l+r)>>1;
        push(v, l, r);
        walk1(v << 1, l, md, x, y, diff, die);
        walk1(v << 1 | 1, md+1, r, x, y, diff, die);
    }
    int query(int x, int y) {
        int ans = 0;
        while (x < N) {
            x = walk0(1, 0, N-1, x, y);
            // cerr << x << '\n';
            if (x == N) break;
            bool die = false;
            int diff = 0;
            walk1(1, 0, N-1, x, y, diff, die);
            ans += diff;
            x += diff;;
        }
        return ans;
    }
    void print(int v, int l, int r) {
        if (l == r) {
            cerr << last[v] << ' ';
        } else {
            int md = (l+r)>>1;
            push(v, l, r);
            print(v << 1, l, md);
            print(v << 1 | 1, md+1, r);
        }
        if (v == 1) cerr << '\n';
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, Q; cin >> N >> Q;
    vector<int> A(N);
    for (int &a : A) cin >> a;
    ST st(N);
    st.init(1, 0, N-1, A);
    while (Q--) {
        int t, x, y; cin >> t >> x >> y; --x;
        if (t == 1) {
            st.modify(1, 0, N-1, x, y);
        } else {
            cout << st.query(x, y) << '\n';
        }
    }
}