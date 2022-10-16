#include <bits/stdc++.h>

using namespace std;

int n;
char typ[100005];
string s[100005];
int can[26];
int nac[26];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> typ[i] >> s[i];
    for (int i = 0; i < 26; ++i) can[i] = 1;
    for (int i = 1; i < n; ++i) {
        if (typ[i] == '?') can[s[i][0]-'a'] = 0;
        else if (typ[i] == '.') {
            for (int j = 0; j < s[i].size(); ++j) can[s[i][j]-'a'] = 0;
        }
        else {
            for (int j = 0; j < 26; ++j) nac[j] = 0;
            for (int j = 0; j < s[i].size(); ++j) nac[s[i][j]-'a'] = 1;
            for (int j = 0; j < 26; ++j) if (!nac[j]) can[j] = 0;
        }
        int cnt = 0;
        for (int j = 0; j < 26; ++j) cnt += can[j];
        if (cnt == 1) {
            int tot = 0;
            for (int j = i + 1; j < n; ++j) if (typ[j] != '.') ++tot;
            cout << tot << endl;
            return 0;
        }
    }
    cout << 0 << endl;
}