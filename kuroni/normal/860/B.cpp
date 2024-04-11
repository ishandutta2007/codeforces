#include <bits/stdc++.h>
using namespace std;

const int N = 70005;

int n;
string s[N];
map<string, int> gl, lc[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (int j = 0; j < 9; j++) {
            string cur = "";
            for (int k = j; k < 9; k++) {
                cur += s[i][k];
                gl[cur]++;
                lc[i][cur]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        string ans = s[i];
        for (int j = 0; j < 9; j++) {
            string cur = "";
            for (int k = j; k < 9; k++) {
                cur += s[i][k];
                if (lc[i][cur] == gl[cur]) {
                    if (ans.size() > cur.size()) {
                        ans = cur;
                    }
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
}