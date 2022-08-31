#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2005;
int n, m, k;
int ans[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == 'D') continue;
            if (c == 'U' && i % 2 == 0) {
                ans[j]++;
                continue;
            }
            if (c == 'R') {
                if (i + j < m) {
                    ans[i + j]++;
                }
            }
            if (c == 'L') {
                if (j - i >= 0) {
                    ans[j - i]++;
                }
            }
        }
    }
    for (int i = 0; i < m; i++) cout << ans[i] << " ";
    return 0;
}