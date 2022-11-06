#include <bits/stdc++.h>

using namespace std;

const int N = 150005;

int main() {
    
    string s;
    cin >> s;
   
    int ans = 1;
    int n = s.size();
    if (s[0] != s[n - 1]) {
        int l1 = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                break;
            }
            l1++;
        }
        int l2 = 1;
        for (int i = n - 2; i >= l1; i--) {
            if (s[i] == s[i + 1]) {
                break;
            }
            l2++;
        }
        if (l1 == n) {
            l2 = 0;
        }
        ans = l1 + l2;
    }
    
    int cur = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            cur++;
            ans = max(ans, cur);
        } else {
            cur = 1;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}