#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 100;
string s;
int q;
int lrg[maxN];
int pref[maxN][26];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> s;
    lrg[s.size() - 1] = s.size() - 1;
    for (int i = (int)s.size() - 2; i >= 0; i--) {
        if (s[i] != s[i + 1]) lrg[i] = i;
        else lrg[i] = lrg[i + 1];
    }
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 26; j++) {
            pref[i][j] = (s[i] == (char)(j + 'a'));
            if (i) pref[i][j] += pref[i - 1][j];
        }
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (r - l + 1 <= 1) {
            cout << "Yes\n";
            continue;
        }
        if (lrg[l] >= r) {
            cout << "No\n";
            continue;
        }
        if (s[l] != s[r]) {
            cout << "Yes\n";
            continue;
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            int a = pref[r][i];
            if (l) a -= pref[l - 1][i];
            if (a) cnt++;
        }
        if (cnt >= 3) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}