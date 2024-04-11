#include <bits/stdc++.h>

using namespace std;

int n;
long long d[500005];
long long s[500005];
long long cnt[500005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> d[i];
    sort(d + 1, d + n + 1, greater <long long>());
    for (int i = 1; i <= n; ++i) s[i] = s[i-1] + d[i];
    long long l = 0, r = n;
    long long t_more = 0, t_less = 0, u_more = 0, u_less = 0;
    for (int i = n; i >= 1; --i) {
            //cout << t_more * (i + 1) + t_less << ' ' << u_more * i - u_less << endl;
        long long val = t_more * (i + 1) + t_less + 1ll * i * (i + 1) - s[i];
        r = min(r, val);
        val = s[i] - u_more * i - u_less - 1ll * i * (i - 1);
        if (i < val) return cout << -1 << endl, 0;
        l = max(l, val);

        t_more += cnt[i];
        t_less -= cnt[i] * i;
        u_more += cnt[i-1];
        u_less -= cnt[i-1] * (i - 1);
        ++cnt[d[i]];
        if (d[i] >= i) ++t_more;
        else t_less += d[i];
        if (d[i] >= i - 1) ++u_more;
        else u_less += d[i];
    }

    int parity = s[n] % 2;
    if (l % 2 != parity) ++l;
    if (r % 2 != parity) --r;
    if (l > r) return cout << -1 << endl, 0;
    for (int i = l; i <= r; i += 2) cout << i << ' '; cout << endl;
    return 0;
}