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
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll ans = m;
        vector<int> lens;
        for (int i = 0; i + 1 < m; i++) {
            lens.emplace_back(a[i + 1] - a[i] - 1);
        }
        lens.emplace_back(n + a[0] - a[m - 1] - 1);
        sort(lens.begin(), lens.end());
        reverse(lens.begin(), lens.end());
        int putted = 0;
        for (int i = 0; i < lens.size(); i++) {
            if (lens[i] > putted * 2 + 1) {
                ans += 2 * putted + 1;
                putted += 2;
            }
            else if (lens[i] == putted * 2 + 1) {
                ans += 2 * putted;
                putted += 1;
            }
            else {
                ans += lens[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}