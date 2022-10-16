/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string base (string s) {
    string t;
    int cntb = 0;
    for (char c : s) {
        if (c != 'B') {
            t += c;
        } else {
            cntb++;
        }
    }
    s = t;
    while (true) {
        int pos = -1;
        for (int i = 0; i + 1 < (int) s.size(); i++) {
            if (s[i] == s[i + 1]) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            break;
        } else {
            t.clear();
            for (int i = 0; i < (int) s.size(); i++) {
                if (i != pos && i != pos + 1) {
                    t += s[i];
                }
            }
            s = t;
        }
    }
    if (cntb % 2 == 1) {
        s += 'B';
    }
    return s;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        string u, v;
        cin >> u >> v;
        cout << (base(u) == base(v) ? "YES" : "NO") << "\n";
    }

    return 0;
}