#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;
string s;
int main() {
   // freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i == 0 || s[i] != s[i - 1]) {
            for (int j = i; j <= s.size(); j++) {
                if (j == s.size() || s[j] != s[i]) {
                    if ((j - i) % 2 == 0) ans++;
                    break;
                }
            }
        }
    }
    cout << ans;
    return 0;
}