#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    
    string ans;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' && k > cnt) {
            ans += s[i];
            k--;
            cnt++;
        }
        if (s[i] == ')' && cnt > 0) {
            ans += s[i];
            k--;
            cnt--;
        }
        if (k == 0) break;
    }
    
    cout << ans << endl;
    return 0;
}