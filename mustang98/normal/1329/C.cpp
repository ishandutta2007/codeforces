#include <bits/stdc++.h>
 
using namespace std;
 
const int max_n = 2333444, inf = 1000111222;
 
int t, h1, h2, n, a[max_n], lev[max_n];
vector<int> ans;
 
bool ok(int v) {
    while (a[2 * v] || a[2 * v + 1]) {
        if (a[2 * v] > a[2 * v + 1]) {
            v = 2 * v;
        } else {
            v = 2 * v + 1;
        }
    }
    return lev[v] > h2;
}
 
void proc(int v) {
    while (a[2 * v] || a[2 * v + 1]) {
        int to = 2 * v;
        if (a[2 * v] < a[2 * v + 1]) {
            to = 2 * v + 1;
        }
        a[v] = a[to];
        v = to;
    }
    a[v] = 0;
}
 
void solve(int root) {
    if (a[root] == 0) {
        return;
    }
    while (ok(root)) {
        ans.push_back(root);
        proc(root);
    }
    solve(2 * root);
    solve(2 * root + 1);
}
 
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &h1, &h2);
        n = (1 << h1) - 1;
        memset(a, 0, 8 * n + 10);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            lev[i] = lev[i / 2] + 1;
        }
        ans.clear();
        solve(1);
        long long sum = accumulate(a + 1, a + (1 << h2), 0LL);
        printf("%I64d\n", sum);
        for (int id : ans) {
            printf("%d ", id);
        }
        puts("");
    }
    return 0;
}