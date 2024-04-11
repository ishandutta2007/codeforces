#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, t;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        if (*min_element(s.begin(), s.end()) == *max_element(s.begin(), s.end())) {
            cout << (n - 1) / 3 + 1 << '\n';
        } else {
            int ans = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == 'R' && s[(i + n - 1) % n] == 'L') {
                    int cnt = 0;
                    for (int j = i; s[j] == 'R'; (++j) %= n) {
                        cnt++;
                    }
                    ans += cnt / 3;
                }
                if (s[i] == 'L' && s[(i + 1) % n] == 'R') {
                    int cnt = 0;
                    for (int j = i; s[j] == 'L'; (j += n - 1) %= n) {
                        cnt++;
                    }
                    ans += cnt / 3;
                }
            }
            cout << ans << '\n';
        }
    }
}