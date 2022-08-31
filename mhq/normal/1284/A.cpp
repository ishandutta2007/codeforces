#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 25;
string s[maxN], t[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n, m, q;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int j = 0; j < m; j++) cin >> t[j];
    cin >> q;
    while (q--) {
        int y;
        cin >> y;
        y--;
        cout << s[y % n] + t[y % m] << '\n';
    }
    return 0;
}