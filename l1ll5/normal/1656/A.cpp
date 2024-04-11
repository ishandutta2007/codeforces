#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int N = 5000 + 5;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i += 1) {
            cin >> v[i];
        }
        int mx = 1, mn = 1;
        for (int i = 1; i <= n; i += 1) {
            if (v[i] > v[mx]) mx = i;
            if (v[i] < v[mn]) mn = i;
        }
        cout << mn << ' ' << mx << '\n';
    }
    return 0;
}