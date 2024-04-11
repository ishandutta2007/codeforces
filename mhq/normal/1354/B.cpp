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
        int lst[3] = {-1, -1, -1};
        int best = s.size() + 1;
        for (int i = 0; i < s.size(); i++) {
            lst[s[i] - '1'] = i;
            int mn = min({lst[0], lst[1], lst[2]});
            if (mn == -1) continue;
            best = min(best, i - mn + 1);
        }
        if (best > s.size()) best = 0;
        cout << best << '\n';
    }
    return 0;
}