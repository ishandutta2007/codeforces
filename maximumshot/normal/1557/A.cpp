#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

void work() {
    cout.precision(20);
    cout << fixed;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        ll total = 0;
        for (int i = 0; i < n; i++)
            total += a[i];
        ld res = -1e18;
        ll cur = 0;
        for (int i = 0; i + 1 < n; i++) {
            cur += a[i];
            res = max(res, ld(cur) / ld(i + 1) + ld(total - cur) / ld(n - i - 1));
        }
        cout << res << "\n";
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    work();

    return 0;
}