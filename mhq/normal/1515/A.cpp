#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 105;
int w[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, x;
        cin >> n >> x;
        int s = 0;
        for (int i = 1; i <= n; i++) {
            cin >> w[i];
            s += w[i];
        }
        sort(w + 1, w + n + 1);
        if (s == x) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            int s = 0;
            for (int i = 1; i <= n; i++) {
                s += w[i];
                if (s == x) {
                    assert(i < n);
                    swap(w[i], w[i + 1]);
                    break;
                }
            }
            for (int i = 1; i <= n; i++) cout << w[i] << " ";
            cout << '\n';
        }
    }
    return 0;
}