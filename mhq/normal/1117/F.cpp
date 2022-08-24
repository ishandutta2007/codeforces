#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = (int)1e5 + 100;
int t[4 * maxN];
int symb[maxN];
int n, p;
int can[20][20];
string s;
int get(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return (get(v + v, tl, tm, l, min(tm, r)) | get(v + v + 1, tm + 1, tr, max(tm + 1, l), r));
}
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = 1 << (symb[tl]);
        return ;
    }
    int tm = (tl + tr) / 2;
    build(v + v, tl, tm);
    build(v + v + 1, tm + 1, tr);
    t[v] = (t[v + v] | t[v + v + 1]);
}
int nxt[maxN][20];
vector < int > all[20];
int val[(1 << 17) + 10];
bool dp[(1 << 17) + 20];
int cnt[20];
int num[(1 << 17) + 20];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        symb[i] = c - 'a';
        all[symb[i]].push_back(i);
        cnt[symb[i]]++;
    }
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p; j++) {
            cin >> can[i][j];
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < p; j++) {
            nxt[i][j] = nxt[i + 1][j];
        }
        if (i + 1 <= n) nxt[i][symb[i + 1]] = i + 1;
    }
    build(1, 1, n);
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p; j++) {
            if (can[i][j]) continue;
            for (int v : all[i]) {
                int u = nxt[v][j];
                if (u == 0) continue;
                if (u > nxt[v][i] && nxt[v][i] != 0) continue;
                int msk = get(1, 1, n, v + 1, u - 1);
                int msk1 = msk | (1 << i);
                int msk2 = msk | (1 << j);
                int msk3 = msk1 | (1 << j);
                val[msk]++;
                val[msk1]--;
                val[msk2]--;
                val[msk3]++;
            }
        }
    }
    for (int bit = 0; bit < p; bit++) {
        for (int mask = 0; mask < (1 << p); mask++) {
            if (mask & (1 << bit)) continue;
            val[mask ^ (1 << bit)] += val[mask];
        }
    }
    int best = n;
    dp[0] = true;
    for (int i = 1; i < (1 << p); i++) {
        for (int bit = 0; bit < p; bit++) {
            if (i & (1 << bit)) {
                num[i] = num[i ^ (1 << bit)] + cnt[bit];
                if (!val[i]) dp[i] |= dp[i ^ (1 << bit)];
            }
        }
        if (dp[i]) best = min(best, n - num[i]);
    }
    cout << best;
}