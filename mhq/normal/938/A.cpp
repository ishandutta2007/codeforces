#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    cin >> s;
    while (1) {
        bool ok = false;
        int ind = -1;
        for (int i = 0; i + 1 < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y') {
                if (s[i + 1] == 'a' || s[i + 1] == 'e' || s[i + 1] == 'i' || s[i + 1] == 'o' || s[i + 1] == 'u' || s[i + 1] == 'y') {
                    ok = true;
                    ind = i + 1;
                }
            }
        }
        if (!ok) break;
        string t;
        for (int i = 0; i < s.size(); i++) {
            if (i == ind) continue;
            t += s[i];
        }
        s = t;
    }
    cout << s;
    return 0;
}