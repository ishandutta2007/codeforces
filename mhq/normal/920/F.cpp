#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 10;
const int maxN = 3 * (int)1e5 + 10;
int lp[N];
int d[N];
vector < int > pr;
int n, m;
int a[maxN];
void calc() {
    for (int i = 2; i <= N; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] < N; j++) {
            lp[i * pr[j]] = pr[j];
        }
    }
    d[1] = 1;
    for (int i = 2; i < N; i++) {
        int t = i;
        int p = lp[t];
        int exp = 0;
        while (t > 1) {
            if (lp[t] != p) break;
            t = t / lp[t];
            exp++;
        }
        d[i] = d[t] * (exp + 1);
    }
}
int mx[4 * maxN];
long long sum[4 * maxN];
void build(int v, int tl, int tr) {
    if (tl == tr) {
        sum[v] = a[tl];
        mx[v] = a[tl];
        return ;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    sum[v] = sum[2 * v] + sum[2 * v + 1];
    mx[v] = max(mx[2 * v], mx[2 * v + 1]);
}
long long get_sum(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) return sum[v];
    int tm = (tl + tr) / 2;
    if (r <= tm) return get_sum(2 * v, tl, tm, l, r);
    if (l > tm) return get_sum(2 * v + 1, tm + 1, tr, l, r);
    return get_sum(2 * v, tl, tm, l, tm) + get_sum(2 * v + 1, tm + 1, tr, tm + 1, r);
}
void upd(int v, int tl, int tr, int l, int r) {
    if (mx[v] <= 2) return;
    if (tl == tr) {
        a[tl] = d[a[tl]];
        mx[v] = a[tl];
        sum[v] = a[tl];
        return ;
    }
    int tm = (tl + tr) / 2;
    if (r <= tm) {
        upd(2 * v, tl, tm, l, r);
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
        sum[v] = sum[2 * v] + sum[2 * v + 1];
        return ;
    }
    if (l > tm) {
        upd(2 * v + 1, tm + 1, tr, l, r);
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
        sum[v] = sum[2 * v] + sum[2 * v + 1];
        return ;
    }
    upd(2 * v, tl, tm, l, tm);
    upd(2 * v + 1, tm + 1, tr, tm + 1, r);
    mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    sum[v] = sum[2 * v] + sum[2 * v + 1];
    return ;
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    calc();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 2) cout << get_sum(1, 1, n, l, r) << '\n';
        if (type == 1) upd(1, 1, n, l, r);
    }
    return 0;
}