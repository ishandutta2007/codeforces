#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s, a[5];
    cin >> s;
    for (int i = 0; i < 5; ++i) {
        cin >> a[i];
        if (a[i][0] == s[0] || a[i][1] == s[1]) return cout << "YES" << endl, 0;
    }
    cout << "NO" << endl;
    return 0;
}