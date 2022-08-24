//#define _GLIBCXX_DEBUG
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
int n, q;
const int maxN = 2e5 + 10;
int a[maxN];
int last[maxN];
int cnt[maxN];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        last[a[i]] = i;
        cnt[a[i]]++;
    }
    int start = 1;
    int ans = n;
    while (start <= n) {
        int mx_d = last[a[start]];
        int z = start;
        while (z <= mx_d) {
            mx_d = max(mx_d, last[a[z]]);
            z++;
        }
        int mx_cnt = 0;
        for (int i = start; i <= mx_d; i++) mx_cnt = max(mx_cnt, cnt[a[i]]);
        ans -= mx_cnt;
        start = mx_d + 1;
    }
    cout << ans << '\n';
    return 0;
}