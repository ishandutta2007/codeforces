#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 205;
int x[maxN], y[maxN];
bool marked[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= 2 * n; i++) {
            marked[i] = false;
        }
        for (int i = 1; i <= k; i++) {
            cin >> x[i] >> y[i];
            marked[x[i]] = marked[y[i]] = true;
        }
        vector<int> z;
        for (int i = 1; i <= 2 * n; i++) {
            if (!marked[i]) z.emplace_back(i);
        }
        for (int c = 0; c < n - k; c++) {
            x[c + 1 + k] = z[c];
            y[c + 1 + k] = z[c + n - k];
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (x[i] > y[i]) swap(x[i], y[i]);
                if (x[j] > y[j]) swap(x[j], y[j]);
                if (x[j] > y[i] || x[i] > y[j]) continue;
                if (x[i] <= x[j] && y[j] <= y[i]) continue;
                if (x[j] <= x[i] && y[i] <= y[j]) continue;
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}