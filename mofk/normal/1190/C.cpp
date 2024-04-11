#include <bits/stdc++.h>

using namespace std;

int win(void) {
    return cout << "tokitsukaze" << endl, 0;
}
int draw(void) {
    return cout << "once again" << endl, 0;
}
int lose(void) {
    return cout << "quailty" << endl, 0;
}

int n, k;
string s;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k >> s;
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i) if (s[i] == s[0]) ++l; else break;
    for (int i = n - 1; i >= 0; --i) if (s[i] == s[n-1]) ++r; else break;
    if (l == n || r == n) return win();
    if (s[0] == s[n-1]) {
        if (l + r + k >= n) return win();
        return draw();
    }
    else {
        if (l + k >= n || r + k >= n) return win();
        for (int i = 0; i + k <= n; ++i) {
            int j = n - k - i;
            {
                int nl, nr;
                if (i <= l) nl = i + k; else nl = l;
                if (j <= r) nr = j; else nr = r;
                if (i + k < n) {
                    if (nl + k < n && nr + k < n) return draw();
                }
                else {
                    if (nl + k + k < n) return draw();
                }
            }
            {
                int nl, nr;
                if (i <= l) nl = i; else nl = l;
                if (j <= r) nr = j + k; else nr = r;
                if (i > 0) {
                    if (nl + k < n && nr + k < n) return draw();
                }
                else {
                    if (nr + k + k < n) return draw();
                }
            }
        }
        return lose();
    }
    return 0;
}