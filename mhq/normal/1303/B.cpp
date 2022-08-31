#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, g, b;
        cin >> n >> g >> b;
        int cn = n;
        n = (n + 1) / 2;
        int k = (n + g - 1) / g - 1;
        cout << max((1LL * b * k + n), (long long)cn) << '\n';
    }
    return 0;
}