#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
        f[i]--;
    }
    sort(f.rbegin(), f.rend());
    int res = 0;
    for (int i = 0; i < n; i += k)
        res += f[i] * 2;
    cout << res;
    return 0;
}