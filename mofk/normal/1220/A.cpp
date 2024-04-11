#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    string s;
    cin >> n >> s;
    int n0 = 0, n1 = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'z') ++n0;
        if (s[i] == 'n') ++n1;
    }
    for (int i = 1; i <= n1; ++i) cout << 1 << ' ';
    for (int i = 1; i <= n0; ++i) cout << 0 << ' ';
    return 0;
}