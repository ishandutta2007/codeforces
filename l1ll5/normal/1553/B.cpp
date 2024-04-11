#include<bits/stdc++.h>
using namespace std;
const int N = 1000000 + 5;
using LL = long long;
void work() {
    string s, t;
    cin >> s;
    cin >> t;
    for (int i = 0; i < s.length(); i += 1) {
        bool ok = 1;
        int len = 0;
        for (int j = i; j < s.length(); j += 1) {
            if (s[j] != t[len]) {
                ok = 0;
                break;
            }
            bool ok2 = 1;
            int tp = 0;
            for (int k = len; k < t.length(); k += 1) {
                if (j - tp < 0) {
                    ok2 = 0;
                    break;
                }
                if (t[k] != s[j - tp]) {
                    ok2 = 0;
                    break;
                }
                tp++;
            }
            if (ok2) {
                cout << "YES\n";
                return;
            }
            len++;
        }

    }
    cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {

        work();
    }

}