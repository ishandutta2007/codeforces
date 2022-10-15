/**
 * @author Macesuted (macesuted@outlook.com)
 * @copyright Copyright (c) 2021
 */

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define maxn 200005

typedef pair<int, int> pii;

void work(void) {
    int n;
    string str;
    cin >> n >> str;
    str = ' ' + str;
    for (register int l = 1; l <= n; l++)
        for (register int r = l; r <= n; r++) {
            int cnt[2] = {0, 0};
            for (register int i = l; i <= r; i++) cnt[str[i] - 'a']++;
            if (cnt[0] == cnt[1]) return cout << l << ' ' << r << endl, void();
        }
    cout << -1 << ' ' << -1 << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    int _ = 1;
    cout << setprecision(11);
    cin >> _;
    while (_--) work();
    return 0;
}