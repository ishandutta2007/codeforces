#include <bits/stdc++.h>
using namespace std;
using LL = long long;
void work() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pos;
    vector<int> suma(n), sumb(n), sumc(n);
    for (int i = 0; i < n; i += 1) {
        if (s[i] == 'a') pos.push_back(i);
        suma[i] = (s[i] == 'a');
        if (i) suma[i] += suma[i - 1];
        sumb[i] = (s[i] == 'b');
        if (i) sumb[i] += sumb[i - 1];
        sumc[i] = (s[i] == 'c');
        if (i) sumc[i] += sumc[i - 1];
    }
    int ans = 1'000'000'000;
    for (int i = 0; i < pos.size(); i += 1) {
        for (int j = i + 1; j < i + 20; j += 1) {
            if (j >= pos.size()) break;
            int l = pos[i], r = pos[j];
            int sa, sb, sc;
            sa = (l == 0) ? suma[r] : suma[r] - suma[l - 1];
            sb = (l == 0) ? sumb[r] : sumb[r] - sumb[l - 1];
            sc = (l == 0) ? sumc[r] : sumc[r] - sumc[l - 1];
            if (sa > sb && sa > sc) ans = min(ans, r - l + 1);
        }
    }
    if (ans == 1'000'000'000) ans = -1;
    cout << ans << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        work();
    }
}