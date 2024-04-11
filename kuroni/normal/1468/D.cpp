#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, t, m, a, b, s[N];

bool check(int u, int tim) {
    for (int i = u; i >= 1; i--) {
        if (s[i] + u + 1 - i > tim) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> m >> n >> a >> b;
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
        }
        sort(s + 1, s + n + 1);
        int tim = (a < b ? b - 1 : m - b);
        int le = 0, ri = min(n, abs(a - b) - 1);
        while (le <= ri) {
            int mi = (le + ri) / 2;
            if (check(mi, tim)) {
                le = mi + 1;
            } else {
                ri = mi - 1;
            }
        }
        cout << ri << '\n';
    }
}