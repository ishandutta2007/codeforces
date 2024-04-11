#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int t = (2 * n / 3);
    int TOT = 0;
    for (int i = 0; i < t; i++) {
        cout << i << " " << 0 << '\n';
        TOT++;
    }
    for (int i = 0; i < t; i += 2) {
        cout << i << " " << 3 << '\n';
        TOT++;
    }
    while (TOT < n) {
        cout << (int)((n - TOT + 4) * 1e4) << " " << (int)((n - TOT + 4) * 1e4) << '\n';
        TOT++;
    }
    return 0;
}