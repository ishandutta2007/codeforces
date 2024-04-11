#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int tst;
bool ok(string& s) {
    bool ok1 = false;
    bool ok2 = false;
    bool ok3 = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') ok1 = true;
        if (s[i] >= 'a' && s[i] <= 'z') ok2 = true;
        if (s[i] >= 'A' && s[i] <= 'Z') ok3 = true;
    }
    return ok1 && ok2 && ok3;
}
char f[3] = {'0', 'a', 'A'};
void solve() {
    string s;
    cin >> s;
    if (ok(s)) {
        cout << s << '\n';
        return ;
    }
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 3; j++) {
            char cp = s[i];
            s[i] = f[j];
            if (ok(s)) {
                cout << s << '\n';
                return ;
            }
            s[i] = cp;
        }
    }
    for (int i = 0; i + 1 < s.size(); i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                char cp1 = s[i];
                char cp2 = s[i + 1];
                s[i] = f[j];
                s[i + 1] = f[k];
                if (ok(s)) {
                    cout << s << '\n';
                    return ;
                }
                s[i] = cp1;
                s[i + 1] = cp2;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> tst;
    while (tst--) solve();
    return 0;
}