#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 305;
int a[maxN * maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> all;
        for (int i = 1; i <= n * m; i++) {
            cin >> a[i];
            all.emplace_back(a[i], i);
        }
        sort(all.begin(), all.end());
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            int from = m * (i - 1);
            int to = from + m - 1;
            vector<int> row;
            for (int z = from; z <= to; z++) {
                row.emplace_back(all[z].second);
            }
            for (int x = 0; x < row.size(); x++) {
                for (int y = x + 1; y < row.size(); y++) {
                    if (a[row[x]] < a[row[y]] && row[x] < row[y]) cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}