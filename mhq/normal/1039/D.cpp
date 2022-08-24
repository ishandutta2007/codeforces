#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 2e5;
vector < int > g[maxN];
int n;
vector < int > start[maxN];
int timer = 0;
int hg[maxN], ord[maxN];
void dfs(int v, int p) {
    timer++;
    ord[v] = timer;
    for (int to : start[v]) {
        if (to == p) continue;
        dfs(to, v);
        g[ord[v]].push_back(ord[to]);
    }
}
int calc_for(int v, int k) {
    if (k > n) return 0;
    int ans = 0;
    hg[v] = 0;
    int mx1 = 0, mx2 = 0;
    for (int to : g[v]) {
        ans += calc_for(to, k);
        if (hg[to] > mx1) {
            mx2 = mx1;
            mx1 = hg[to];
        }
        else mx2 = max(mx2, hg[to]);
    }
    if (mx1 + 1 + mx2 >= k) {
        hg[v] = 0;
        ans++;
    }
    else hg[v] = mx1 + 1;
    return ans;
}
int BLOCK = 1000;
int val[maxN];
int main() {
    srand(123 + 23123123 + 123123 - 123123);
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    bool test = false;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        if (u == 36861 && i == 1) test = true;
        start[u].push_back(v);
        start[v].push_back(u);
    }
    dfs(1, -1);
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += g[i].size();
    assert(sum == n - 1);
    memset(val, -1, sizeof val);
    BLOCK = min(BLOCK, n);
    for (int i = 1; i <= BLOCK; i++) {
        val[i] = calc_for(1, i);
    }
    /*if (test) {
        cout << (clock() / CLOCKS_PER_SEC);
        return 0;
    }*/
    vector < int > all;
    int st = BLOCK + 1;
    while (st <= n) {
        all.push_back(st);
        val[st] = calc_for(1, st);
        int l = st;
        int r = n;
        while (r - l > 0) {
            int mid = (r + l) / 2 + 1;
            if (calc_for(1, mid) == val[st]) l = mid;
            else r = mid - 1;
        }
        l = st;
        for (; l <= r; l++) val[l] = val[st];
        st = r + 1;
    }
    for (int i = 1; i <= n; i++) cout << val[i] << '\n';
    return 0;
}