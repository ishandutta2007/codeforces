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
        int n;
        cin >> n;
        string s;
        cin >> s;
        string t = "abacaba";
        bool can = false;
        string pp;
        for (int i = 0; i + t.size() - 1 < n; i++) {
            bool ok = true;
            for (int j = 0; j < t.size(); j++) {
                if (s[i + j] != t[j] && s[i + j] != '?') {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            string ns = s;
            for (int j = 0; j < t.size(); j++) {
                ns[i + j] = t[j];
            }
            for (int j = 0; j < n; j++) {
                if (ns[j] == '?') ns[j] = 'z';
            }
            int ff = 0;
            for (int j = 0; j + t.size() - 1 < n; j++) {
                bool tok = true;
                for (int p = 0; p < t.size(); p++) {
                    if (ns[j + p] != t[p]) {
                        tok = false;
                        break;
                    }
                }
                if (tok) ff++;
            }
            assert(ff > 0);
            if (ff == 1) {
                can = true;
                pp = ns;
                break;
            }
        }
        if (can) {
            cout << "Yes\n";
            cout << pp << '\n';
        }
        else {
            cout << "No\n";
        }
    }
    return 0;
}