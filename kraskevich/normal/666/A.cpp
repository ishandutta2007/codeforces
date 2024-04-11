#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

bool diff(const string& s, int p1, int p2, int len) {
    for (int i = 0; i < len; i++)
        if (s[p1 + i] != s[p2 + i])
            return true;
    return false;
}
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.length();
    set<string> res;
    for (int i = 5; i < n; i++)
        for (int len = 2; len <= 3 && len + i <= n; len++) {
            vector<char> can2(n + 1);
            vector<char> can3(n + 1);
            if (len == 2)
                can2[i + len] = true;
            else
                can3[i + len] = true;
            for (int j = i + len; j < n; j++) {
                if (j + 2 <= n) {
                    can2[j + 2] |= can3[j];
                    if (diff(s, j - 2, j, 2))
                        can2[j + 2] |= can2[j];
                }
                if (j + 3 <= n) {
                    can3[j + 3] |= can2[j];
                    if (diff(s, j - 3, j, 3))
                        can3[j + 3] |= can3[j];
                }
            }
            if (can2.back() || can3.back())
                res.insert(s.substr(i, len));
        }
    cout << res.size() << "\n";
    for (auto q : res)
        cout << q << "\n";
}