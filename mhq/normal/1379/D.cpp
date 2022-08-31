#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
int n, h, m, k;
int c[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> h >> m >> k;
    int len = m / 2 - k;
    vector < int > gg;
    for (int i = 1; i <= n; i++) {
        int tr;
        cin >> tr;
        int p;
        cin >> p;
        p %= (m / 2);
        c[i] = p;
        gg.emplace_back(p);
        gg.emplace_back(p + m / 2);
    }
    int best = 0;
    int where = -1;
    sort(gg.begin(), gg.end());
    int r = 0;
    for (int i = 0; i < gg.size(); i++) {
        r = max(r, i);
        while (r + 1 < gg.size() && gg[r + 1] - gg[i] <= len) r++;
        if (best < (r - i + 1)) {
            best = r - i + 1;
            where = gg[i];
        }
    }
    where %= (m / 2);
    cout << (n - best) << " " << (where) << '\n';
    int p1 = where;
    int p2 = where + len;
    for (int i = 1; i <= n; i++) {
        if ((c[i] >= p1 && c[i] <= p2) || (c[i] + m / 2 >= p1 && c[i] + m / 2 <= p2)) continue;
        cout << i << " ";
    }
    return 0;
}