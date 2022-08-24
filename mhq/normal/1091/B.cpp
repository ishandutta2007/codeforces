#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    srand(239);
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x = 0;
    ll y = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int xx, yy;
        cin >> xx >> yy;
        x += xx;
        y += yy;
    }
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        x += a;
        y += b;
    }
    cout << x / n << " " << y / n;
    return 0;
}