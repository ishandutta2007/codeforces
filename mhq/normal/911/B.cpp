#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e5 + 10;
int n, a, b;
//int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> a >> b;
    int ans = -1;
    for (int i = 1; i <= (n - 1); i++) {
        int x1 = (a / i);
        int x2 = (b / (n - i));
        if (x1 < 1 || x2 < 1) continue;
        ans = max(ans, min(x1, x2));
    }
    cout << ans;
}