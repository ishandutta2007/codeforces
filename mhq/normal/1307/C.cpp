#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
string s;
const int maxN = (int)1e5 + 100;
int cnt[maxN][26];
ll f[26][26];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 26; j++) {
            if (i) cnt[i][j] = cnt[i - 1][j];
            f[j][s[i] - 'a'] += cnt[i][j];
        }
        cnt[i][s[i] - 'a']++;
    }
    ll mx = 0;
    for (int i = 0; i < 26; i++) {
        mx = max(mx, (ll)cnt[s.size() - 1][i]);
        for (int j = 0; j < 26; j++) {
            mx = max(mx, f[i][j]);
        }
    }
    cout << mx;
    return 0;
}