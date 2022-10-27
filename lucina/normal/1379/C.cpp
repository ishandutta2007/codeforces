#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
struct item{
    int a, b;
    item (int a = 0, int b = 0) : a(a), b(b) {}
    bool operator < (const item& other) const  {
        return a < other.a;
    }
};
item x[nax];
int n;
long long m;
long long suf[nax];

void solve() {
    cin >> m >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> x[i].a >> x[i].b;
    }
    sort(x + 1, x + 1 + n);

    long long ans = 0;
    suf[n + 1] = 0;
    for (int i = n; i >= 1; -- i)
        suf[i] = suf[i + 1] + x[i].a;

    for (int i = 1 ; i <= n ; ++ i) {
        int best = x[i].b;
        int l = 1, r = n, f = -1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (x[mid].a > best) {
                f = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        long long cur = 0;
        long long res = m;
        if (f != -1) {
            long long has = n - f + 1;
            has = min(has, m);
            f = n - has + 1;
            cur += suf[f];
            res -= has;
        }
        if ((f > i || f == -1))
            if (res > 0) cur += x[i].a, -- res;
            else continue;
        if (res > 0) cur += 1LL * best * res;
        ans = max(ans, cur);
    }

    cout << ans << '\n';
}


int main () {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    not ryza again.
*/