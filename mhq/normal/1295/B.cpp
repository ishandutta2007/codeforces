#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 100;
int nxt[27][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, x;
        cin >> n >> x;
        string s;
        cin >> s;
        int bal = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') bal++;
            else bal--;
        }
        int cur = 0;
        int cnt = 0;
        bool inf = false;
        for (int i = 0; i < s.size(); i++) {
            if (bal == 0) {
                if (cur == x) {
                    inf = true;
                    break;
                }
            }
            else if (bal > 0) {
                if ((x - cur) % bal == 0 && x >= cur) cnt++;
            }
            else {
                if ((x - cur) % bal == 0 && x <= cur) cnt++;
            }
            if (s[i] == '0') cur++;
            else cur--;
        }
        if (inf) cout << -1 << '\n';
        else cout << cnt << '\n';
    }
    return 0;
}