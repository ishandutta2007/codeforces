#include <bits/stdc++.h>
using namespace std;

int n, k, t;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> k >> s;
        int zer = 0, one = 0;
        bool chk = true;
        for (int i = 0; i < k; i++) {
            int tmp = -1;
            for (int j = i; j < n; j += k) {
                if (s[j] != '?') {
                    if (tmp != -1 && s[j] - '0' != tmp) {
                        chk = false;
                        break;
                    }
                    tmp = s[j] - '0';
                }
            }
            if (tmp != -1) {
                (tmp == 0 ? zer : one)++;
            }
        }
        if (max(zer, one) > k / 2) {
            chk = false;
        }
        cout << (chk ? "YES\n" : "NO\n");
    }
}