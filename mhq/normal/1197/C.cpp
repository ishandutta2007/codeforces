#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    vector < int > a(n);
    for (int& v : a) {
        cin >> v;
    }
    ll ans = -a[0] + a[n - 1];
    vector < int > b;
    for (int i = 0; i + 1 < n; i++) {
        b.push_back(a[i] - a[i + 1]);
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < k - 1; i++) {
        ans += b[i];
    }
    cout << ans;
    return 0;
}