#include <bits/stdc++.h>
using namespace std;
int n;
bool used[26];
char t[(int)1e5 + 10];
string c[(int)1e5 + 10];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    int pos = 1;
    bool rok = false;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        cin >> c[i];
        if (!rok) {
            if (t[i] == '?') {
                used[c[i][0] - 'a'] = true;
            }
            if (t[i] == '.') {
                for (int j = 0; j < c[i].size(); j++) {
                    used[c[i][j] - 'a'] = true;
                }
            }
            if (t[i] == '!') {
                for (int j = 0; j < 26; j++) {
                    bool ok = true;
                    for (int k = 0; k < c[i].size(); k++) {
                        if (j == c[i][k] - 'a') ok = false;
                    }
                    if (ok) used[j] = true;
                }
            }
            int num = 0;
            for (int j = 0; j < 26; j++) {
                if (!used[j]) num++;
            }
            if (num == 1) {
                    rok = true;
            }
        }
        else {
            if (t[i] == '?' && i != n) ans++;
            else if (t[i] == '!') ans++;
        }
    }
    cout << ans;
    return 0;
}