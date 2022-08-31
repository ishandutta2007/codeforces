#include <bits/stdc++.h>
using namespace std;
int n, m, k;
const int maxN = 2 * (int)1e5 + 10;
int f[maxN];
int a[maxN];
bool used[maxN];
int t[maxN];
void add(int i, int d) {
    for (; i <= n; i = (i | (i - 1)) + 1) {
        t[i] += d;
    }
}
int sum(int r) {
    int res = 0;
    while (r >= 1) {
        res += t[r];
        r = r & (r - 1);
    }
    return res;
}
int ne(int l, int r) {
    return sum(r) - sum(l - 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        add(i, 1);
    }
    sort(a + 1, a + n + 1);
    int curind = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (used[i] == true) continue;
        while (a[i] - a[curind] >= m || used[curind]) curind++;
        //cout << curind << '\n';
        //if (i == 2) cout << f[2] << " " << f[0] << '\n';
        int q = ne(curind, i);
        if (q >= k) {
            q = q - k + 1;
            ans += q;
            int pt = 0;
            for (int j = i; j >= curind; j--) {
                if (pt >= q) break;
                if (used[j]) continue;
                pt++;
                add(j, -1);
                used[j] = true;
            }
        }
    }
    cout << ans;
    return 0;
}