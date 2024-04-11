#include<cstdio> /// for faster scanf
#include<bits/stdc++.h>
using namespace std;
int const nax = 4e5 + 5;

struct segtree {
/// ooooopps again I will never remember it : (
int sg[nax * 4];
int tag[nax * 4];

segtree () {
    memset(sg, 0, sizeof(sg));
    memset(tag, 0, sizeof(tag));
}

void push(int v) {
    if (!tag[v]) return;
    sg[v << 1] += tag[v];
    sg[v << 1 | 1] += tag[v];
    tag[v << 1] += tag[v];
    tag[v << 1 | 1] += tag[v];
    tag[v] = 0;
}

void add (int v, int x, int y, int l, int r, int to_add) {
    if (l > r) return;
    if (x != y) push(v); /// lol forget to push
    if (l == x && r == y) {
        sg[v] += to_add;
        tag[v] += to_add;
        if (x != y) push(v);
    } else {
        int mid = x + y >> 1;
        if (r <= mid) add(v << 1, x, mid, l, r, to_add);
        else if (l > mid) add(v << 1 | 1, mid + 1, y, l, r, to_add);
        else add(v << 1, x, mid, l, mid, to_add)
            , add(v << 1 | 1, mid + 1, y, mid + 1, r, to_add);
        sg[v] = max(sg[v << 1], sg[v << 1 | 1]);
    }
}
};
int n;
struct segment {
    int l, r, t;
    bool operator < (const segment &other) const {
        return r < other.r;
    }
    void read() {
        scanf("%d %d %d", &l, &r, &t);
    }
};
segment a[nax];
int com[nax];
int topCom;
vector <pair <int, int>> to_update[nax];

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) {
        a[i].read();
        com[++ topCom] = a[i].l;
        com[++ topCom] = a[i].r;
    }
    sort(com + 1, com + topCom + 1);
    int m = unique(com + 1, com + topCom + 1) - com - 1;

    auto where = [&] (int x) ->int {
        return lower_bound(com + 1, com + m + 1, x) - com;
    };

    for (int i = 1; i <= n ; ++ i) {
        auto &[l, r, t] = a[i];
        l = where(l);
        r = where(r);
        to_update[r + 1].emplace_back(l + 1, t);
    }

    segtree t1, t2;
    int ans = 0;

    for (int i = 1 ; i <= m + 1; ++ i) {
        for (auto [l, t] : to_update[i]) {
            if (t == 1) t1.add(1, 1, m + 1, 1, l - 1, 1);
            else t2.add(1, 1, m + 1, 1, l - 1, 1);
        }
        int cur = max(t1.sg[1], t2.sg[1]);
        ans = max(ans, cur);
        t1.add(1, 1, m + 1, i, i, cur);
        t2.add(1, 1, m + 1, i, i, cur);
    }

    printf("%d\n", ans);
}
/*
    Good Luck
        -Lucina
*/