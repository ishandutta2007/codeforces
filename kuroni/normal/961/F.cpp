#include <bits/stdc++.h>
using namespace std;

const int N = 1E6 + 5;

int n, len, ran[4 * N], eve[4 * N];
char t[4 * N];
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s;
    len = 4 * n - 1;
    t[0] = '^'; t[len + 1] = '#';
    for (int i = 1; i <= len; i += 4) {
        t[i] = s[i / 4];
        t[i + 2] = s[n - 1 - i / 4];
    }
    for (int i = 1, l = 1, r = 1; i <= len / 2; i++) {
        eve[i] = -2;
        ran[i] = ran[l + r - i];
        if (i + ran[i] >= r) {
            l = 2 * i - r;
            while (t[l - 1] == t[r + 1]) {
                l--;
                r++;
            }
            ran[i] = r - i;
        }
        if (i % 4 == 2) {
            eve[i - ran[i]] = max(eve[i - ran[i]], i);
        }
    }
    int mid = (n + 1) / 2;
    for (int i = 1, mx = -2; i <= 4 * mid - 3; i++) {
        mx = max(mx, eve[i]);
        if (i % 4 == 1) {
            cout << max(-1, (mx - i + 1) / 2) << " ";
        }
    }
}