#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = (int)1e5 + 100;
string s;
int len[2 * maxN];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> s;
    int st = s.size();
    s = s + s;
    int n = s.size();
    len[0] = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) len[i] = 1;
        else len[i] = len[i - 1] + 1;
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, len[i]);
    }
    cout << min(mx, st);
    return 0;
}