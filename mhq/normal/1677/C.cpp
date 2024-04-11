#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
int a[maxN], b[maxN];
int nxt[maxN];
bool used[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    //[x, x]     5 + |2 - 5| + |5 - 3| + |3 - 4| + |4 - 2|
    //5 + 3 +
    while (tst--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            nxt[a[i]] = b[i];
        }
        vector<int> cyc;
        for (int i = 1; i <= n; i++) {
            used[i] = false;
        }
        int cnt_odd = 0;
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                int c = i;
                int sz = 0;
                while (!used[c]) {
                    used[c] = true;
                    c = nxt[c];
                    sz++;
                }
                if (sz & 1) cnt_odd++;
            }
        }
        int need = (n - cnt_odd) / 2;
        ll ans = 0;
        for (int i = 1; i <= need; i++) {
            ans += 2 * (n - i + 1);
            ans -= 2 * i;
        }
        cout << ans << '\n';
    }
    return 0;
}