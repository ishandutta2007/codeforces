#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 3 * (int)1e5 + 100;
int a[maxN], b[maxN];
int n;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    vector < pair < int, int > > f1, f2;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        if (a[i] > b[i]) {
            f1.emplace_back(a[i], i);
        }
        else {
            f2.emplace_back(b[i], i);
        }
    }
    if (f1.size() > f2.size()) {
        cout << f1.size() << '\n';
        sort(f1.begin(), f1.end());
        for (auto t : f1) cout << t.second << " ";
    }
    else {
        cout << f2.size() << '\n';
        sort(f2.begin(), f2.end());
        reverse(f2.begin(), f2.end());
        for (auto t : f2) {
            cout << t.second << " ";
        }
    }
    return 0;
}