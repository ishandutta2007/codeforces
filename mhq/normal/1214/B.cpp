#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int b, g, n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> b >> g >> n;
    int cnt = 0;
    for (int i = 0; i <= n; i++) {
        if (i <= b && n - i <= g) cnt++;
    }
    cout << cnt;
    return 0;
}