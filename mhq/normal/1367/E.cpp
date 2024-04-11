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
        vector < int > cnt(26);
        string s;
        cin >> s;
        for (char& c : s) {
            cnt[c - 'a']++;
        }
        int best = 0;
        for (int len = 1; len <= n; len++) {
            int sz = len / __gcd(len, k);
            int tot = 0;
            for (int& v : cnt) {
                tot += (v / sz) * sz;
            }
            if (tot >= len) best = len;
        }
        cout << best << '\n';
    }
    return 0;
}