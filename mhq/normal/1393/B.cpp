#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
int cnt[maxN];
int t2, t4;
void ch(int x, int by) {
    t2 -= cnt[x] / 2;
    t4 -= cnt[x] / 4;
    cnt[x] += by;
    t2 += cnt[x] / 2;
    t4 += cnt[x] / 4;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        ch(x, +1);
    }
    int q;
    cin >> q;
    while (q--) {
        char f;
        cin >> f;
        int p;
        cin >> p;
        if (f == '+') ch(p, +1);
        else ch(p, -1);
        if (t2 >= 4 && t4 >= 1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}