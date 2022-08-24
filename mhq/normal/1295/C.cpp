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
//    /freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        string s, t;
        cin >> s >> t;
        int n = s.size();
        for (int i = n; i >= 0; i--) {
            for (int j = 0; j < 26; j++) {
                if (i == n) nxt[j][i] = n + 1;
                else {
                    nxt[j][i] = nxt[j][i + 1];
                    if (s[i] - 'a' == j) nxt[j][i] = i + 1;
                }

            }
        }
        int steps = 0;
        int cur = 0;
        while (true) {
            steps++;
            int cur_pos = 0;
            if (nxt[t[cur] - 'a'][cur_pos] > n) {
                steps = -1;
                break;
            }
            while (true) {
                if (cur == t.size()) break;
                if (nxt[t[cur] - 'a'][cur_pos] > n) break;
                cur_pos = nxt[t[cur] - 'a'][cur_pos];
                cur++;
            }
            if (cur == t.size()) break;
        }
        cout << steps << '\n';
    }
    return 0;
}