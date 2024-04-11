#include <bits/stdc++.h>

using namespace std;

string s;
long long cnt[26];
long long a[26][26];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        int x = s[i] - 'a';
        for (int j = 0; j < 26; ++j) a[j][x] += cnt[j];
        ++cnt[x];
    }
    long long ans = 0;
    for (int i = 0; i < 26; ++i) ans = max(ans, cnt[i]);
    for (int i = 0; i < 26; ++i) for (int j = 0; j < 26; ++j) ans = max(ans, a[i][j]);
    cout << ans << endl;
    return 0;
}