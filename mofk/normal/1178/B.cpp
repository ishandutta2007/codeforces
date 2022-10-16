#include <bits/stdc++.h>

using namespace std;

string s;
int w[1000006];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    int n = s.size();
    for (int i = 1; i < n; ++i) if (s[i] == 'v' && s[i-1] == 'v') w[i] = w[i-1] + 1; else w[i] = w[i-1];
    long long ans = 0;
    int cnt = 0;
    for (int i = n - 2; i >= 0; --i) {
        if (s[i] == 'o') ans += 1ll * cnt * w[i-1];
        else if (s[i+1] == 'v') ++cnt;
    }
    cout << ans << endl;
    return 0;
}