#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    string s, t;
    cin >> s >> t;
    int c47 = 0, c74 = 0;
    for (int i = 0; i < s.size(); i++) {
        c47 += (s[i] == '4' && t[i] == '7');
        c74 += (s[i] == '7' && t[i] == '4');
    }
    cout << max(c47, c74);
    return 0;
}