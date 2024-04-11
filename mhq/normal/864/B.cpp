#include <bits/stdc++.h>
using namespace std;
char s[202];
int main() {
    //freopen("jellous.in", "r", stdin);
    //freopen("jellous.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for ( int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    int ans = 0;
    bool mark[26];
    for ( int i = 1; i <= n; i++) {
        int cur = 0;
        for ( int i = 0; i <= 25; i++) mark[i] = false;
        if ( s[i] - 'a' < 0 || s[i] - 'a' > 25) continue;
        cur++;
        mark[s[i] - 'a'] = true;
        for ( int j = i + 1; j <= n; j++) {
            if ( s[j]  - 'a' < 0 || s[j] - 'a' > 25) break;
            if ( !mark[s[j] - 'a']) {
                mark[s[j] - 'a'] = true;
                cur++;
            }
        }
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}