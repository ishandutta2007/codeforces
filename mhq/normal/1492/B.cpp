#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
int p[maxN];
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        vector<int> ps;
        int mx = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            mx = max(mx, p[i]);
            if (mx == p[i]) {
                ps.emplace_back(i);
            }
        }
        ps.emplace_back(n + 1);
        for (int i = ps.size() - 2; i >= 0; i--) {
            int from = ps[i];
            int to = ps[i + 1] - 1;
            for (int x = from; x <= to; x++) cout << p[x] << " ";
        }
        cout << '\n';
    }
    return 0;
}