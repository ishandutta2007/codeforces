#include <bits/stdc++.h>
using namespace std;
string s;
int ans[28];
bool t[28];
int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        t[s[i] - 'a'] = true;
    }
    for (int i = 0; i < 26; i++) {
        if (!t[i]) continue;
        int lef, rig;
        lef = 10000000;
        rig = -1;
        int an = 0;
        int cur = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] - 'a' == i) {
                an = max(j - cur, an);
                cur = j;
                lef = min(lef, j);
                rig = max(rig, j);
            }
        }
        an = max(lef + 1, an);
        an = max((int)s.size() - rig, an);
        ans[i] = an;
    }
    int an1 = 10000000;
    for (int i = 0; i < 26; i++) {
        if (ans[i] == 0) continue;
        an1 = min(ans[i], an1);
    }
    cout << an1;
    return 0;
}