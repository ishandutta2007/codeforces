#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int tst;
const int maxN = 55;
int cnta[maxN], cntb[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m;
        memset(cnta, 0, sizeof cnta);
        memset(cntb, 0, sizeof cntb);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char c;
                cin >> c;
                if (c == '1') {
                    cnta[i]++;
                    cntb[j]++;
                }
            }
        }
        int r = 0, c = 0;
        for (int i = 1; i <= n; i++) {
            if (cnta[i] == 0) r++;
        }
        for (int i = 1; i <= m; i++) {
            if (cntb[i] == 0) c++;
        }
        cout << (min(r, c) % 2 == 0 ? "Vivek" : "Ashish") << '\n';
    }
    return 0;
}