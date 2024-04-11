#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
bool tok[maxN];
int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
//      freopen("input.txt", "r", stdin);
        int tst;
        cin >> tst;
        while (tst--) {
            int n;
            cin >> n;
            bool ok = false;
            int who = -1;
            for (int i = 1; i <= n; i++) {
                tok[i] = false;
            }
            for (int i = 1; i <= n; i++) {
                int cnt;
                cin >> cnt;
                bool hs = false;
                for (int j = 1; j <= cnt; j++) {
                    int p;
                    cin >> p;
                    if (!tok[p] && !hs) {
                        tok[p] = true;
                        hs = true;
                    }
                }
                if (!hs) {
                    ok = true;
                    who = i;
                }
            }
            if (!ok) cout << "OPTIMAL\n";
            else {
                int f = -1;
                for (int i = 1; i <= n; i++) {
                    if (!tok[i]) {
                        f = i;
                        break;
                    }
                }
                assert(f != -1);
                cout << "IMPROVE\n" << who << " " << f << '\n';
            }
        }

        return 0;
    }