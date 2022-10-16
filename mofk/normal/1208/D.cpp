#include <bits/stdc++.h>

using namespace std;

int n;
long long s[200005];
int ans[200005];
long long t[200005];

void upd(int x, int v) {
    for (; x <= n; x += x & -x) t[x] += v;
}
int lb(long long x) {
    int ret = 0;
    for (int i = 20; i >= 0; --i) {
        if (ret + (1 << i) <= n && t[ret + (1 << i)] <= x) {
            ret += 1 << i;
            x -= t[ret];
        }
    }
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> s[i];
    for (int i = 1; i <= n; ++i) upd(i, i);
    for (int i = n; i >= 1; --i) {
        ans[i] = lb(s[i]) + 1;
        upd(ans[i], -ans[i]);
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' '; cout << endl;
    return 0;
}