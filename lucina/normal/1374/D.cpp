#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

int n, k;
int a[nax];

int main () {
    int T;
    cin.tie(0)->sync_with_stdio(false);

    for (cin >> T ; T -- ;) {
        cin >> n >> k;

        map <int, int> ss;

        for (int i = 1 ; i <= n ; ++ i) {
            cin >> a[i];
            a[i] %= k;
            if (a[i] == 0) a[i] = k;
            a[i] = k - a[i];
            if (a[i]) ++ ss[a[i]];
        }

        long long ans = 0;

        for (auto &p : ss) {
            ans = max(ans, 1LL * (p.second - 1) * k + p.first + 1);
        }

        cout << ans << '\n';
    }
}