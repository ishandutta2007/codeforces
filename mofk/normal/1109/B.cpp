#include <bits/stdc++.h>

using namespace std;

string s;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    int n = s.size();
    int flag = 0;
    for (int i = 0; i < n; ++i) if (s[i] != s[0] && i != n - 1 - i) flag = 1;
    if (!flag) return cout << "Impossible" << endl, 0;
    int ans = 2;
    string t = s + s;
    for (int i = 1; i < n; ++i) {
        string u = t.substr(i, n);
        if (u == s) continue;
        int flag = 1;
        for (int j = 0; j < n - 1 - j; ++j) if (u[j] != u[n-1-j]) {
            flag = 0;
            break;
        }
        if (flag) {
            ans = 1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}