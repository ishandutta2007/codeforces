#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
string s;
int q;
const int maxN = (int)1e5 + 100;
typedef bitset < maxN > bs;
bs all[26];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        all[s[i] - 'a'][i] = true;
    }
    bs one;
    for (int i = 0; i < s.size(); i++) one[i] = true;
    cin >> q;
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int i;
            char c;
            cin >> i >> c;
            i--;
            all[s[i] - 'a'][i] = false;
            s[i] = c;
            all[s[i] - 'a'][i] = true;
        }
        else {
            int l, r;
            string p;
            cin >> l >> r >> p;
            l--;
            r--;
            if (r - l + 1 < p.size()) {
                cout << 0 << '\n';
                continue;
            }
            bs cur = one;
            for (int i = 0; i < p.size(); i++) {
                cur &= (all[p[i] - 'a'] >> i);
            }
            cout << (cur >> l).count() - (cur >> (r - (int)p.size() + 2)).count() << '\n';
        }
    }
    return 0;
}