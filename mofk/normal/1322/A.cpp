#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> s;
    int d = 0, ans = 0, c = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') ++d; else --d;
        if (d < 0) ++c;
        else if (d == 0) {
            if (c) ans += c + 1;
            c = 0;
        }
    }
    if (d) ans = -1;
    cout << ans << endl;
    return 0;
}