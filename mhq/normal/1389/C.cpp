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
        string s;
        cin >> s;
        vector < int > cnt(10);
        for (char& c : s) {
            cnt[c - '0']++;
        }
        int mx = *max_element(cnt.begin(), cnt.end());
        for (int a = 0; a < 10; a++) {
            for (int b = 0; b < 10; b++) {
                if (b == a) continue;
                int need = 0;
                int sz = 0;
                for (char& c : s) {
                    int d = c - '0';
                    if (need == 0) {
                        if (d == a) {
                            sz++;
                            need ^= 1;
                        }
                    }
                    else if (need == 1) {
                        if (d == b) {
                           sz++;
                           need ^= 1;
                        }
                    }
                }
                if (sz % 2 == 1) sz--;
                mx = max(mx, sz);
            }
        }
        cout << s.size() - mx << '\n';
    }
    return 0;
}