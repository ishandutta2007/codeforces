#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 1e5 + 10;
int l[maxN];
int p[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    ll s = 0;
    cin >> n >> m;
    vector < pair < int, int > > all;
    for (int i = 1; i <= m; i++) {
        cin >> l[i];
        s += l[i];
        all.emplace_back(l[i], i);
    }
    if (s < n) {
        cout << -1;
        return 0;
    }
    s -= l[1];
    p[1] = 1;
    for (int i = 2; i <= m; i++) {
        int at_least = p[i - 1] + 1;
        while (n - at_least + 1 > s) at_least++;
        p[i] = at_least;
        if (p[i] + l[i] - 1 > n) {
            cout << -1;
            return 0;
        }
        s -= l[i];
    }
    for (int i = 1; i <= m; i++) cout << p[i] << " ";
    return 0;
}