#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, q;
const int maxN = 6 * (int)1e5 + 10;
int p[maxN];
int pos[maxN], val[maxN];
int ans[4 * maxN];
int sumL[4 * maxN];
int sumR[4 * maxN];
int cnt[4 * maxN];
int real_val[maxN];
vector < int > all;
int N;
int cur_pos[maxN];
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int inv_2 = (mod + 1) / 2;
int pw2[maxN], inv2[maxN];
int valSingle[maxN];
int sumLSingle[maxN];
int sumRSingle[maxN];

void merge(int v) {
    cnt[v] = sum(cnt[2 * v], cnt[2 * v + 1]);
    sumL[v] = sum(sumL[2 * v], mult(pw2[cnt[2 * v]], sumL[2 * v + 1]));
    sumR[v] = sum(sumR[2 * v], mult(inv2[cnt[2 * v]], sumR[2 * v + 1]));
    ans[v] = sum(ans[2 * v], ans[2 * v + 1]);
    ans[v] = sum(ans[v], mult(sumL[2 * v], mult(inv2[cnt[2 * v]], sumR[2 * v + 1])));
}

void updateSingle(int v, int pos) {
    sumL[v] = mult(real_val[pos], sumLSingle[cnt[v]]);
    sumR[v] = mult(real_val[pos], sumRSingle[cnt[v]]);
    ans[v] = mult(mult(real_val[pos], real_val[pos]), valSingle[cnt[v]]);
}

int gg[maxN];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        cnt[v] = gg[tl];
        updateSingle(v, tl);
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    merge(v);
}

void upd(int v, int tl, int tr, int pos, int by) {
    if (tl == tr) {
        cnt[v] += by;
        updateSingle(v, pos);
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) upd(2 * v, tl, tm, pos, by);
    else upd(2 * v + 1, tm + 1, tr, pos, by);
    merge(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    valSingle[0] = 0;
    pw2[0] = inv2[0] = 1;
    for (int i = 1; i < maxN; i++) pw2[i] = mult(2, pw2[i - 1]);
    for (int i = 1; i < maxN; i++) inv2[i] = mult(inv_2, inv2[i - 1]);
    int cur_sum = 0;
    for (int i = 1; i < maxN; i++) {
        valSingle[i] = sum(valSingle[i - 1], mult(cur_sum, inv2[i - 1]));
        cur_sum = sum(cur_sum, pw2[i - 1]);
        sumLSingle[i] = cur_sum;
        sumRSingle[i] = sum(sumRSingle[i - 1], inv2[i - 1]);
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        all.emplace_back(p[i]);
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> pos[i] >> val[i];
        all.emplace_back(val[i]);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    int N = all.size();
    for (int i = 0; i < N; i++) {
        real_val[i + 1] = all[i];
    }
    for (int i = 1; i <= n; i++) {
        int he = lower_bound(all.begin(), all.end(), p[i]) - all.begin() + 1;
        cur_pos[i] = he;
        gg[he]++;
    }
    build(1, 1, N);
    cout << mult(inv_2, ans[1]) << '\n';
    for (int i = 1; i <= q; i++) {
        upd(1, 1, N, cur_pos[pos[i]], -1);
        int he = lower_bound(all.begin(), all.end(), val[i]) - all.begin() + 1;
        cur_pos[pos[i]] = he;
        upd(1, 1, N, cur_pos[pos[i]], 1);
        cout << mult(inv_2, ans[1]) << '\n';
    }
    return 0;
}