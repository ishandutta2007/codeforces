#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using ll = long long;
using namespace std;

const int N = 1e5 + 2;

int cnt[N][26];

signed main() {
    string s;
    cin >> s;
    int n = s.size();
    cnt[0][s[0] - 'a']++;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 26; j++)
            cnt[i][j] = cnt[i - 1][j];
        cnt[i][s[i] - 'a']++;
    }
    ll res = *max_element(cnt[n - 1], cnt[n - 1] + 26);
    for (char f = 'a'; f <= 'z'; f++) for (char se = 'a'; se <= 'z'; se++) {
        ll cur = 0;
        for (int i = n - 1; i > 0; i--)
            if (s[i] == f)
                cur += cnt[i - 1][se - 'a'];
        res = max(res, cur);
    }
    cout << res << '\n';
}