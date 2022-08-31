#include <bits/stdc++.h>
using namespace std;
const int maxN = 2 * (int)1e5 + 10;
int a[maxN];
int n;
int t[maxN];
void upd(int i, int d) {
    for (; i <= n; i = (i | (i - 1)) + 1) {
        t[i] += d;
    }
}
int get(int r) {
    int res = 0;
    while (r >= 1) {
        res += t[r];
        r = r & (r - 1);
    }
    return res;
}
int sum(int l, int r) {
    if (l > r) return 0;
    return get(r) - get(l - 1);
}
vector < int > g[maxN];
int main() {
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > n) a[i] = n;
        g[a[i]].push_back(i);
    }
    long long ans = 0;
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < g[i].size(); j++) {
            upd(g[i][j], 1);
        }
        ans += sum(i + 1, a[i]);
    }
    cout << ans;
}