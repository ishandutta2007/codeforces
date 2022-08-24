#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int a, b, n;
        cin >> a >> b >> n;
        if (n % 3 == 0) cout << a << "\n";
        else if (n % 3 == 1) cout << b << '\n';
        else cout << (a ^ b) << '\n';
    }
    return 0;
}