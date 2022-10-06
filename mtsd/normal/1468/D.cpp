#include<bits/stdc++.h>
using namespace std;
const int M = 1000000007;
using P = pair<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    for (int _ = 0; _ < T; ++_) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        vector<int> s(m);
        for (int i = 0; i < m; ++i) {
            cin >> s[i];
        }
        sort(s.begin(), s.end());
        reverse(s.begin(), s.end());
        if (b < a) {
            b = n - b + 1;
            a = n - a + 1;
        }
        int c = (b - a) - 1;
        int l = b - 2;
        int ans = 0;
        for (int i = 0, j = 0; i < c && j < m; ++i) {
            while (j < m && s[j] > l - i) {
                ++j;
            }
            if (j == m) break;
            ++ans;
            ++j;
        }
        cout << ans << '\n';
    }
    return 0;
}