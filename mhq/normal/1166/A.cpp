#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int f[26];
int c2(int x) {
    return (x * (x - 1)) / 2;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        f[s[0] - 'a']++;
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        ans += c2(f[i] / 2) + c2((f[i] + 1)/  2);
    }
    cout << ans;
    return 0;
}