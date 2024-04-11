#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e6 + 10;
int A, B, C, D;
ll tot[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n, s;
    cin >> n >> s;
    if (s < 2 * n) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for (int i = 1; i < n; i++) cout << 1 << " ";
    cout << s - (n - 1) << '\n';
    cout << n << '\n';
    return 0;
}