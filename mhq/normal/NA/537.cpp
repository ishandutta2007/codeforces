#include <bits/stdc++.h>
using namespace std;
int val[3][52];
string s[3];
int mx[3];
int ans[3];
int main() {
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < 3; i++) {
        cin >> s[i];
        for (int j = 0; j < s[i].size(); j++) {
            if (s[i][j] >= 'a' && s[i][j] <= 'z') {
                val[i][s[i][j] - 'a']++;
            }
            else {
                val[i][s[i][j] - 'A' + 26]++;
            }
        }
        for (int j = 0; j < 52; j++) {
            mx[i] = max(mx[i], val[i][j]);
        }
    }
    int t = 0;
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        if (n != 1) ans[i] = min((int)s[i].size(), mx[i] + n);
        else {
            if (mx[i] != s[i].size()) {
                ans[i] = mx[i] + 1;
            }
            else ans[i] = max(mx[i] - 1, 1);
        }
        t = max(t, ans[i]);
    }
    for (int i = 0; i < 3; i++) {
        if (ans[i] == t) cnt++;
    }
    if (cnt > 1) {
        cout << "Draw";
        return 0;
    }
    if (ans[0] == t) {
        cout << "Kuro";
    }
    else if (ans[1] == t) {
        cout << "Shiro";
    }
    else cout << "Katie";
    return 0;
}