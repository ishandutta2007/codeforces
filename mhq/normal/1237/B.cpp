#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e5 + 100;
int a[maxN];
int b[maxN];
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x] = i;
    }
    vector < int > all;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        b[x] = i;
        all.push_back(i);
    }
    sort(all.begin(), all.end(), [&](int x, int y) {
        return a[x] < a[y];
    });
    int cnt = 0;
    int mx = -n - 100;
    for (int i = 0; i < all.size(); i++) {
        if (b[all[i]] < mx) {
            cnt++;
        }
        mx = max(mx, b[all[i]]);
    }
    cout << cnt;
    return 0;
}