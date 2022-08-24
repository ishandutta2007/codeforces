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
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        int L = -2e9 - 228;
        int R = 2e9 + 228;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            L = max(L, a[i] - x);
            R = min(R, a[i] + x);
            if (L > R) {
                cnt++;
                L = a[i] - x;
                R = a[i] + x;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}