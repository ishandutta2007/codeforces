#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> pv;
        int val = 0;
        int cntw = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'W') {
                val++;
                cntw++;
                if (i > 0 && s[i - 1] == 'W') val++;
            }
        }
        if (cntw + k >= n) {
            cout << n + n - 1 << '\n';
            continue;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'W') pv.emplace_back(i);
        }
        vector<int> lens;
        for (int i = 0; i + 1 < pv.size(); i++) {
            lens.emplace_back(pv[i + 1] - pv[i] - 1);
        }
        sort(lens.begin(), lens.end());
        for (int r = 0; r < lens.size(); r++) {
            for (int c = 0; c < lens[r]; c++) {
                if (!k) break;
                val++;
                val++;
                if (c == lens[r] - 1) val++;
                k--;
            }
        }
        val += 2 * k;
        if (cntw == 0 && k > 0) val--;
        cout << val << '\n';
    }
    return 0;
}