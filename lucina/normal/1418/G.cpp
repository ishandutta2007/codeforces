#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int nax = 5e5 + 10;

pair <int, int> operator +(const pair <int, int> &a, const pair <int, int> &b) {
    if (a.first == b.first) {
        return make_pair(a.first, a.second + b.second);
    } else {
        return max(a, b);
    }
}

struct segtree {
    pair <int, int> sg[nax * 4];
    int tag[nax * 4];

    segtree(int n) {
        build(1, 1, n);
    }

    inline void pull(int v) {
        sg[v] = sg[v << 1] + sg[v << 1 | 1];
    }

    void build(int v, int l, int r) {
        if (l == r) {
            sg[v] = make_pair(0, 1);
        } else {
            int mid = l + r >> 1;
            build(v << 1, l, mid);
            build(v << 1 | 1, mid + 1, r);
            pull(v);
        }
    }

    inline void push(int v) {
        if (!tag[v]) return ;
        sg[v << 1].first += tag[v];
        tag[v << 1] += tag[v];
        sg[v << 1 | 1].first += tag[v];
        tag[v << 1 | 1] += tag[v];
        tag[v] = 0;
    }

    void add(int v, int x, int y, int l, int r, int to_add) {
        if (x != y) push(v);
        if (l == x && r == y) {
            sg[v].first += to_add;
            tag[v] += to_add;
            if (x != y) push(v);
        } else {
            int mid = x + y >> 1;
            if (r <= mid) add(v << 1, x , mid, l, r, to_add);
            else if (l > mid) add(v << 1 | 1, mid + 1, y, l, r, to_add);
            else add(v << 1, x, mid, l, mid, to_add)
            , add(v << 1 | 1, mid + 1, y, mid + 1, r, to_add);
            pull(v);
        }
    }
};
vector <int> pos[nax];
int nxt[nax];
int last[nax];
int dp[nax];
int a[nax];
int n;
int64_t ans;
int keep_val[nax];


int main() {


    scanf("%d", &n);

    segtree sg(n);

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", a + i);
        pos[a[i]].push_back(i);
    }

    fill(nxt, nxt + n + 1, -1);

    for (int i = 1 ; i <= n ; ++ i) {
        if (pos[i].empty()) continue;
        auto &p = pos[i];
        for (int i = 0 ; i < int(p.size()) ; ++ i) {
            if (i + 2 < int(p.size()))
                nxt[p[i]] = p[i + 2];
        }
    }

    auto add_prefix = [&](int pos, int val)->void {
        sg.add(1, 1, n, pos, n, val);
    };

    add_prefix(1, -1);

    for (int i = n ; i >= 1 ; -- i) {
        int x = a[i];
        if (last[x]) {
            add_prefix(last[x], -keep_val[last[x]]);
            keep_val[last[x]] = 0;
            if (nxt[last[x]] != -1) {
                add_prefix(nxt[last[x]], -keep_val[nxt[last[x]]]);
                keep_val[nxt[last[x]]] = -1;
                add_prefix(nxt[last[x]], -1);
            }
        }
        sg.add(1, 1, n, i, i, 1);
        if (nxt[i] != -1) {
            add_prefix(nxt[i], -keep_val[nxt[i]]);
            keep_val[nxt[i]] = 1;
            add_prefix(nxt[i], 1);
            add_prefix(i, -1);
            keep_val[i] = -1;
        } else {
            add_prefix(i, -1);
            keep_val[i] = -1;
        }


        if (sg.sg[1].first == 0) ans += sg.sg[1].second;
        last[x] = i;
    }
    /**
        This is wrong for trivial reasons.
        Even if you can find first positino
        such that
        it's valid but it doesn't mean that
        combination with valid subarray later
        is still available.
        Q: How do we fix this?
        A:  ??????
        In fact, we want to count number of
        positions which is equal to zero? right?
        But after this segment tree how do we support it?
        It does sound like segment tree beats.


        -1 ,      ,1
        When prefix sum equal to zero, it means that
        this position is valid
        we want to count number of positions which is
        equal to zero?
        Can we really do that?

    */

    printf("%lld\n", ans);

}