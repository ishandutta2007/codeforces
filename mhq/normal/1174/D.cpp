#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (1 << 18) + 100;
bool used[maxN];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    vector < int > xr;
    int n, x;
    cin >> n >> x;
    xr.push_back(0);
    used[0] = used[x] = true;
    for (int i = 1; i < (1 << n); i++) {
        if (!used[i] && !used[i ^ x]) {
            used[i] = true;
            xr.push_back(i);
            used[i ^ x] = true;
        }
    }
    cout << xr.size() - 1 << '\n';
    for (int i = 0; i + 1 < xr.size(); i++) {
        cout << (xr[i] ^ xr[i + 1]) << " ";
    }
    return 0;
}