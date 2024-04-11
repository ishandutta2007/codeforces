#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 1e5 + 10;
int a[maxN];
const int SZ = 3 * maxN * 32;
int mx[SZ][2];
int nxt[SZ][2];
int sz = 1;
vector<pair<int,int>> que[maxN];
void add(int who, int id) {
    int cur = 0;
    if (mx[cur][0] < id) {
        mx[cur][1] = mx[cur][0];
        mx[cur][0] = id;
    }
    else if (mx[cur][1] < id) {
        mx[cur][1] = id;
    }
    for (int c = 29; c >= 0; c--) {
        int bt = (who >> c) & 1;
        if (nxt[cur][bt] == -1) {
            nxt[cur][bt] = sz++;
        }
        cur = nxt[cur][bt];
        if (mx[cur][0] < id) {
            mx[cur][1] = mx[cur][0];
            mx[cur][0] = id;
        }
        else if (mx[cur][1] < id) {
            mx[cur][1] = id;
        }
    }
}
int BAD[50];
int ans[maxN];
void do_find(int l, int id) {
//    cout << " ? " << l << " " << id << endl;
    int cur = 0;
    int sz_bad = 0;
    int cur_ans = 0;
    for (int c = 29; c >= 0; c--) {
        int cnt_good = 0;
        for (int t = 0; t < sz_bad; t++) {
            if (!(BAD[t] & (1 << c))) {
                cnt_good++;
            }
        }
        if (cur != -1 && nxt[cur][0] != -1) {
            int d = nxt[cur][0];
            if (mx[d][0] >= l) {
                cnt_good++;
            }
            if (mx[d][1] >= l) {
                cnt_good++;
            }
        }
        if (cnt_good >= 2) {
            //move left
            int new_sz = 0;
            for (int t = 0; t < sz_bad; t++) {
                if (!(BAD[t] & (1 << c))) {
                    BAD[new_sz++] = BAD[t];
                }
            }
            sz_bad = new_sz;
            if (cur != -1) cur = nxt[cur][0];
        }
        else {
            cur_ans |= (1 << c);
            if (cur != -1 && nxt[cur][0] != -1) {
                int d = nxt[cur][0];
                if (mx[d][0] >= l) {
                    BAD[sz_bad++] = a[mx[d][0]];
                }
            }
            if (cur != -1) cur = nxt[cur][1];
        }
    }
    ans[id] = cur_ans;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        que[i].clear();
    }
    for (int x = 0; x < sz; x++) {
        mx[x][0] = mx[x][1] = -1;
        nxt[x][0] = nxt[x][1] = -1;
    }
    sz = 1;
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        que[r].emplace_back(l, i);
    }
    for (int i = 1; i <= n; i++) {
        add(a[i], i);
        for (auto& it : que[i]) {
            do_find(it.first, it.second);
        }
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    memset(nxt, -1, sizeof nxt);
    memset(mx, -1, sizeof mx);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}