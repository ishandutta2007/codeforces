#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }
        int mx = a[n - 1] - a[0];
        for (int i = 0; i < n; i++) {
            mx = max(mx, a[(i + n - 1) % n] - a[i]);
        }
        mx = max(mx, a[n - 1] - *min_element(a.begin(), a.begin() + n - 1));
        mx = max(mx, *max_element(a.begin() + 1, a.begin() + n) - a[0]);
        cout << mx << '\n';
    }
    return 0;
}