#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int n, v;
    cin >> n >> v;
    if (n - 1 <= v) {
        cout << n - 1;
        return 0;
    }
    int ans = v + (n - v + 2) * (n - v - 1) / 2;
    cout << ans;
}