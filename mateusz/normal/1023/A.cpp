#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int main() {
    int n, m;
    string s, t;
    cin >> n >> m;
    cin >> s;
    cin >> t;
    
    int star = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            star = i;
            break;
        }
    }
    
    if (star == -1) {
        printf(s == t ? "YES\n" : "NO\n");
        return 0;
    }
    
    bool good = true;
    for (int i = 0; i < star; i++) {
        if (i == m) {
            good = false;
            break;
        }
        good &= s[i] == t[i];
    }
    
    for (int i = 0; i < n; i++) {
        int p1 = n - i - 1;
        int p2 = m - i - 1;
        if (p1 == star) {
            break;
        }
        if (p2 < star) {
            good = false;
            break;
        }
        good &= s[p1] == t[p2];
    }
    
    printf(good ? "YES\n" : "NO\n");
    
}