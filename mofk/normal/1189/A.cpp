#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    string s;
    cin >> n >> s;
    int c0 = 0, c1 = 0;
    for (auto c: s) if (c == '0') ++c0; else ++c1;
    if (c0 != c1) {
        cout << 1 << endl << s << endl;
    }
    else {
        cout << 2 << endl << s[0] << ' ';
        for (int i = 1; i < s.size(); ++i) cout << s[i];
        cout << endl;
    }
    return 0;
}