#include <bits/stdc++.h>
using namespace std;
 
const int M = 105, N = 105;
 
int t, m, n, k;
char s[M][N];
 
char convert(int cur) {
    if (cur < 10) {
        return cur + '0';
    } else if (cur < 36) {
        return cur - 10 + 'a';
    } else {
        return cur - 36 + 'A';
    }
}
 
void solve() {
    cin >> m >> n >> k;
    int cnt = 0, cur = 0;
    for (int i = 1; i <= m; i++) {
        cin >> (s[i] + 1);
        for (int j = 1; j <= n; j++) {
            cnt += (s[i][j] == 'R');
        }
    }
    int di = cnt / k, fi = cnt % k;
    int tmp = 0;
    for (int i = 1; i <= m; i++) {
        if (i & 1) {
            for (int j = 1; j <= n; j++) {
                tmp += (s[i][j] == 'R');
                if (tmp > di + (cur < fi)) {
                    cur++;
                    tmp = 1;
                }
                s[i][j] = convert(cur);
            }
        } else {
            for (int j = n; j >= 1; j--) {
                tmp += (s[i][j] == 'R');
                if (tmp > di + (cur < fi)) {
                    cur++;
                    tmp = 1;
                }
                s[i][j] = convert(cur);
            }
        }
        cout << (s[i] + 1) << '\n';
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
}