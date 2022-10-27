#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
int a[nax];
int b[nax];
int64_t ans[nax * 2];
int n, m, nq;
pair <int, int> q[nax];
int par[nax * 2];
int sz[nax * 2];
int find_par(int x) {
    return x == par[x] ? x : par[x] = find_par(par[x]);
}
int64_t sum[nax * 2];

struct Info {
    int al, ar;
    int pos_in_block;
    Info(){}
    Info(int al, int ar, int pos_in_block) :
        al(al), ar(ar), pos_in_block(pos_in_block) {}
    friend Info merge(const Info &a, const Info &b) {
        Info s;
        s.al = min(a.al, b.al); s.ar = max(a.ar, b.ar);
        s.pos_in_block = max(a.pos_in_block, b.pos_in_block);
        return s;
    }
    int64_t get_cost() {
        int many_up = ar - al + 1;
        if (many_up <= 0) return 0;
        return sum[pos_in_block] - sum[pos_in_block - many_up];
    }
} info[nax * 2];


int main() {
    scanf("%d %d %d", &n, &m, &nq);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", a + i);
    }
    for (int i = 1 ; i <= m ; ++ i) {
        scanf("%d", b + i);
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    merge(a + 1, a + 1 + n, b + 1, b + 1 + m, sum + 1);
    vector <tuple <int, int, int>> joins;
    for (int i = 1, ptr_sum = 1, ptr_b = 1 ; i <= n ; ++ i) {
        while (ptr_sum <= n + m && sum[ptr_sum] <= a[i]) ptr_sum++;
        info[i] = Info(i, i, ptr_sum - 1);
        if (i < n) joins.emplace_back(a[i + 1] - a[i], i, i + 1);
        while (ptr_b <= m && b[ptr_b] < a[i]) ptr_b++;
        if (ptr_b <= m) joins.emplace_back(b[ptr_b] - a[i], i, ptr_b + n);
    }
    for (int i = 1, ptr_sum = 1, ptr_a = 1; i <= m ; ++ i) {
        while (ptr_sum <= n + m && sum[ptr_sum] <= b[i]) ptr_sum++;
        info[i + n] = Info(n + 1, 0, ptr_sum - 1);
        if (i < m) joins.emplace_back(b[i + 1] - b[i], i + n, i + n + 1);
        while (ptr_a <= n && a[ptr_a] < b[i]) ++ ptr_a;
        if (ptr_a <= n) joins.emplace_back(a[ptr_a] - b[i], i + n, ptr_a);
    }
    for (int i = 1 ; i <= n + m ; ++ i) {
        sum[i] += sum[i - 1];
    }
    iota(par + 1, par + 1 + n + m, 1);
    fill(sz + 1, sz + 1 + n + m, 1);
    for (int i = 1 ; i <= nq ; ++ i) {
        scanf("%d", &q[i].first);
        q[i].second = i;
    }
    sort(q + 1, q + 1 + nq);
    sort(joins.rbegin(), joins.rend());
    int64_t s = 0;
    for (int i = 1 ; i <= n + m ; ++ i)
        s += info[i].get_cost();

    for (int i = 1 ; i <= nq ; ++ i) {
        auto [k, id] = q[i];
        while (!joins.empty() && get<0>(joins.back()) <= k) {
            auto [_, u, v] = joins.back();
            joins.pop_back();
            u = find_par(u), v = find_par(v);
            if (u == v) continue;
            if (sz[u] < sz[v]) swap(u, v);
            s -= info[u].get_cost(), s -= info[v].get_cost();
            info[u] = merge(info[u], info[v]);
            par[v] = u;
            sz[u] += sz[v];
            s += info[u].get_cost();
        }
        ans[id] = s;
    }
    for (int i = 1 ; i <= nq ; ++ i) {
        printf("%lld\n", ans[i]);
    }

}