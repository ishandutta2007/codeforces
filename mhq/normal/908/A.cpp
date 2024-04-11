#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        char t = s[i];
        if (s[i] >= '0' && s[i] <= '9' && (s[i] - '0') % 2 == 1) ans++;
        if (s[i] == 'a' || s[i] == 'o' || s[i] == 'e' || s[i] == 'i' || s[i] == 'u') ans++;
    }
    cout << ans;
    return 0;
}