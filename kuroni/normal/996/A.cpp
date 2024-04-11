#include <bits/stdc++.h>
using namespace std;

int n, ans = 0, a[5] = {100, 20, 10, 5, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < 5; i++) {
        ans += n / a[i];
        n %= a[i];
    }
    cout << ans;
}