#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN = 5 * (int)1e4 + 100;
const int BT = 30;
struct node{
    int sm;
    int nxt[2];
    int val[2];
    node() {
        val[0] = val[1] = 0;
        nxt[0] = nxt[1] = -1;
    }
};
int sz = 1;
node t[maxN * (BT + 1)];
int n;
int m;
int a[maxN];
void cl() {
    for (int i = 1; i <= sz; i++) {
        t[i].nxt[0] = t[i].nxt[1] = -1;
        t[i].val[0] = t[i].val[1] = 0;
    }
    sz = 1;
}

int cnt(int val, int x, int who_need) {
    // >= x
    int who = (x ^ val);
    int v = 1;
    int ans = 0;
    for (int bt = 29; bt >= 0; bt--) {
        int now_bit = (who >> bt) & 1;
        int x_bit = (x >> bt) & 1;
        if (t[v].nxt[now_bit ^ 1] != -1 && x_bit == 0) {
            ans += t[t[v].nxt[now_bit ^ 1]].val[who_need];
        }
        if (t[v].nxt[now_bit] == -1) break;
        v = t[v].nxt[now_bit];
        if (bt == 0) {
            ans += t[v].val[who_need];
        }
    }
    return ans;
}

void add(int val, int where) {
    int v = 1;
    for (int bt = 29; bt >= 0; bt--) {
        t[v].val[where]++;
        int bbt = (val >> bt) & 1;
        if (t[v].nxt[bbt] == -1) {
            sz++;
            t[v].nxt[bbt] = sz;
        }
        v = t[v].nxt[bbt];
    }
    t[v].val[where]++;
}


int get(int x) {
    cl();
    int s1 = 0;
    for (int i = 1; i <= n; i++) {
        s1 += cnt(a[i], x, 1);
        add(a[i], 1);
    }
    return s1;
}

int get_sum(int x) {
    cl();
    int s1 = 0;
    for (int bt = 29; bt >= 0; bt--) {
        cl();
        int vl = 0;
        for (int i = 1; i <= n; i++) {
            int bbt = (a[i] >> bt) & 1;
            vl = sum(vl, cnt(a[i], x, bbt ^ 1) % mod);
            add(a[i], bbt);
        }
        s1 = sum(s1, mult(vl, (1 << bt) % mod));
    }
    return s1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    if (m == 0) {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    // f(x) < m  f(x + 1) >= m
    int l = 0;
    int r = (1 << 30);
    while (r - l > 1) {
        int mid = (l + r) / 2;
        auto s = get(mid);
        if (s >= m) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    // l - ok
    int cnt = get(l + 1);
    int ans = get_sum(l + 1);
    int lft = m - cnt;
    ans = sum(ans, mult(lft % mod, l));
    cout << ans;
    return 0;
}