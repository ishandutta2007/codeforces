#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int t;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> s;
        int cnt[2] = {0, 0}, ans = 0;
        for (char c : s) {
            switch (c) {
                case '(': {
                    cnt[0]++;
                    break;
                }
                case ')': {
                    if (cnt[0] > 0) {
                        cnt[0]--;
                        ans++;
                    }
                    break;
                }
                case '[': {
                    cnt[1]++;
                    break;
                }
                case ']': {
                    if (cnt[1] > 0) {
                        cnt[1]--;
                        ans++;
                    }
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
}