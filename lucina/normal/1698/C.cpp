#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
int n;
int64_t a[nax];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        cin >> n;
        map <int64_t, int> cnt;
        for (int i = 1 ; i <= n ; ++ i) {
            cin >> a[i];
            cnt[a[i]] += 1;
        }
        int other = n - cnt[0];
        bool ok = true;
        if (other <= 10) {
            int m = 0;
            for (int i = 1 ; i <= n ; ++ i)
                if (a[i]) a[++ m] = a[i];
            for (int j = 0 ; j < min(3, cnt[0]) ; ++ j)
                a[++ m] = 0;
            n = m;
            for (int i = 1 ;i < n ; ++ i)
            for (int j = i + 1 ; j < n ; ++ j)
            for (int k = j + 1 ; k <= n ; ++ k) {
                if (!cnt[a[i] + a[j] + a[k]])
                    ok = false;
            }
        } else ok = false;
        cout << (ok ? "YES" : "NO") << '\n';
    }
}