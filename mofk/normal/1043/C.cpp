#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int ans[1005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    n = s.size();
    char c = 'a';
    for (int i = n - 1; i >= 0; --i) if (s[i] == c) {
        ans[i] = 1;
        if (c == 'a') c = 'b'; else c = 'a';
    }
    //for (int i = 0; i < n; ++i) if (ans[i]) reverse(s.begin(), s.begin() + i + 1);
    //cerr << s << endl;
    for (int i = 0; i < n; ++i) cout << ans[i] << ' '; cout << endl;
    return 0;
}