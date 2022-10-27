#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
string s;

/**
    find pair of max difference char

    'a' 'a' 'a' 'a' 'a' 'a'
    -1 1 -1 -1 1
*/

bool solve() {
    cin >> s;
    int n = s.size();
    for (int h = 1 ; h <= min(26, n) ; ++ h) {
        int c[26]{};
        memset(c, -1, sizeof(c));
        bool ok = true;
        for (int i = 0 ; i < n ; ++ i) {
            if (c[i % h] == -1) c[i % h] = s[i];
            else if (c[i % h] != s[i]) ok = false;
        }
        memset(c, 0, sizeof(c));
        for (int i = 0 ; i < h ; ++ i) {
            c[s[i] - 'a'] += 1;
            if (c[s[i] - 'a'] > 1) ok = false;
        }
        if (ok) return true;
    }
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}
/**
    sigh...
    too many assignments :)
*/