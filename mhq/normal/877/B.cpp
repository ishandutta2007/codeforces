#include <bits/stdc++.h>
using namespace std;
int a[5005];
int s[5005];
string t;
int main() {
    cin >> t;
    char x;
    s[0] = 0;
    for (int i = 1; i <= t.size(); i++) {
        a[i] = t[i - 1] - 'a';
        s[i] = s[i - 1] + a[i];
    }
    int ans = 0;
    int n = t.size();
    for (int i = 0; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int cur = 0;
            cur += i - s[i];
            cur += s[j] - s[i];
            cur += (n - j) - s[n] + s[j];
            if (cur > ans) ans = cur;
        }
    }
    cout << ans;
    return 0;
}