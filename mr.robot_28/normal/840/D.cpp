#include <bits/stdc++.h>
#pragma GCC optimize 03
#pragma GCC optimize ("Ofast")
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 3e5 + 1;
const int L = 430;
int pr[L][N], b[L], a[N], cnt[N];
 
 
 
int main() {
    int i, j, k, n, l, r, p, top = 0, q;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    int len = sqrt(n);
    if (n / len >= L)
        len = n / L + 1;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    for (i = 1; i <= n; ++i)
    if (cnt[i] >= len) {
        ++top;
        b[top] = i;
        for (j = 1; j <= n; ++j) {
            pr[top][j] = pr[top][j - 1];
            if (a[j] == i)
                ++pr[top][j];
        }
    }
    for (i = 1; i <= n; ++i)
        cnt[i] = 0;
    for (i = 1; i <= q; ++i) {
        cin >> l >> r >> k;
        if (r - l + 1 <= k * len) {
            int x = 1e9;
            for (j = l; j <= r; ++j) {
                ++cnt[a[j]];
                if (cnt[a[j]] * k > (r - l + 1))
                    x = min(x, a[j]);
            }
            if (x == 1e9)
                x = -1;
            cout << x << "\n";
            for (j = l; j <= r; ++j)
                --cnt[a[j]];
        } else {
            int x = -1;
            for (j = 1; j <= top; ++j)
            if (pr[j][r] - pr[j][l - 1] > (r - l + 1) / k) {
                x = b[j];
                break;
            }
            cout << x << "\n";
        }
    }
}