#include <bits/stdc++.h>
using namespace std;


int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = s.size();
        int l = 0, r;
        while (l < n && s[l] != 'a') l++;
        if (l == n) {
            puts("NO");
            continue;
        }
        r = l;
        bool ans = true;
        for (int i = 1; i < n; i++) {
            char cur = 'a' + i;
            if (l && s[l - 1] == cur) l--;
            else if (r < n - 1 && s[r + 1] == cur) r++;
            else {
                ans = false;
            }
        }
        puts(ans ? "YES" : "NO");
    }
}