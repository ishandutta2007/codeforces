#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 10;
int n;
int cnt[maxN];
int h[maxN];
ll k;
int mn = maxN;
int to[maxN];
ll pref[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        mn = min(mn, a);
        mx = max(mx, a);
        cnt[1] += 1;
        cnt[a + 1] -= 1;
    }
    for (int i = 1; i <= mx; i++) {
        cnt[i] += cnt[i - 1];
        pref[i] = cnt[i] + pref[i - 1];
    }
    int l = mx;
    int r = mx;
    while (r > 1) {
        while (l > 1 && pref[r] - pref[l - 2] <= k) l--;
        to[r] = l;
        r--;
    }
    int q = 0;
    int st = mx;
    while (st > mn) {
        q++;
        st = to[st] - 1;
    }
    cout << q;
    return 0;
}