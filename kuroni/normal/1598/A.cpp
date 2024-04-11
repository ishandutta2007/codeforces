#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, t;
string s[2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> s[0] >> s[1];
        bool ok = true;
        for (int i = 1; i < n - 1; i++) {
            if (s[0][i] == '1' && s[1][i] == '1') {
                ok = false;
                break; 
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}