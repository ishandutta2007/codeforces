#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

int n;
string s[MAXN];
bool good[10];

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    s[0] = "0";
    cin >> n;
    for (int i=1; i<=n; i++) cin >> s[i];

    for (int i=1; i<=n; i++) {
        if (s[i-1].length() > s[i].length()) {
            cout << "NO\n";
            return 0;
        } else if (s[i-1].length() < s[i].length()) {
            for (int j=0; j<s[i].length(); j++)
                if (s[i][j] == '?') {
                    if (j == 0) s[i][j] = '1';
                    else s[i][j] = '0';
                }
        } else {
            good[s[i].length()] = 0;
            for (int j=s[i].length()-1; j>=0; j--) {
                if (s[i][j] == '?') {
                    if (s[i-1][j] == '9') good[j] = good[j+1];
                    else good[j] = 1;
                } else {
                    if (s[i][j] < s[i-1][j]) good[j] = 0;
                    else if (s[i][j] == s[i-1][j]) good[j] = good[j+1];
                    else good[j] = 1;
                }
            }

            if (!good[0]) {
                cout << "NO\n";
                return 0;
            }

            bool b = 0;
            for (int j=0; j<s[i].length(); j++) {
                if (!b) {
                    if (s[i][j] == '?') {
                        if (good[j+1]) s[i][j] = s[i-1][j];
                        else s[i][j] = s[i-1][j]+1, b = 1;
                    } else {
                        if (s[i][j] > s[i-1][j]) b = 1;
                    }
                } else {
                    if (s[i][j] == '?') s[i][j] = '0';
                }
            }
        }
    }

    cout << "YES\n";
    for (int i=1; i<=n; i++)
        cout << s[i] << '\n';
    return 0;
}