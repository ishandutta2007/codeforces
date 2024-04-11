#include <bits/stdc++.h>

using namespace std;
string s[2000];
int n;
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    int mx = 0;
    for (int j = 0; j < 7; j++) {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (s[i][j] == '1') cnt++;
        mx = max(mx, cnt);
    }
    cout << mx << "\n";
    return 0;
}