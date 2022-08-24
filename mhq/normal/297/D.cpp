#include <bits/stdc++.h>
using namespace std;
int h, w, k;
bool r[1005][1005];
bool d[1005][1005];
bool nr[1005][1005];
bool nd[1005][1005];
bool invert = false;
int ans[1005][1005];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> h >> w >> k;
    for (int i = 1; i <= 2 * h - 1; i++) {
        if (i % 2 == 1) {
            for (int j = 1; j <= w - 1; j++) {
                char s;
                cin >> s;
                if (s == 'E') {
                    r[(i + 1) / 2][j] = true;
                }
                else r[(i + 1) / 2][j] = false;
            }
        }
        else {
            for (int j = 1; j <= w; j++) {
                char s;
                cin >> s;
                if (s == 'E') {
                    d[(i / 2)][j] = true;
                }
                else d[(i / 2)][j] = false;
            }
        }
    }
    if (k == 1) {
        int ans = 0;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= (w - 1); j++) {
                if (r[i][j]) ans++;
            }
        }
        for (int i = 1; i <= (h - 1); i++) {
            for (int j = 1; j <= w; j++) {
                if (d[i][j]) ans++;
            }
        }
        if (ans * 4 >= 3 * (2 * w * h - w - h)) {
            cout << "YES" << '\n';
            for (int i = 1; i <= h; i++) {
                for (int j = 1; j <= w; j++) {
                    cout << 1 << " ";
                }
                cout << "\n";
            }
        }
        else {
            cout << "NO";
        }
        return 0;
    }
    if (h > w) {
        invert = true;
        for (int i = 1; i <= (h - 1); i++) {
            for (int j = 1; j <= w; j++) {
                nr[j][i] = d[i][j];
            }
        }
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= (w - 1); j++) {
                nd[j][i] = r[i][j];
            }
        }
        swap(h, w);
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= (w - 1); j++) {
                r[i][j] = nr[i][j];
            }
        }
        for (int i = 1; i <= (h - 1); i++) {
            for (int j = 1; j <= w; j++) {
                d[i][j] = nd[i][j];
            }
        }
    }
    ans[1][1] = 1;
    for (int i = 1; i <= w - 1; i++) {
        if (r[1][i]) ans[1][i + 1] = ans[1][i];
        else ans[1][i + 1] = 3 - ans[1][i];
    }
    for (int i = 1; i <= h - 1; i++) {
        int ans1 = 0;
        int ans2 = 0;
        ans[i + 1][1] = 1;
        for (int j = 1; j <= (w - 1); j++) {
            if (r[i + 1][j]) ans[i + 1][j + 1] = ans[i + 1][j];
            else ans[i + 1][j + 1] = 3 - ans[i + 1][j];
        }
        for (int j = 1; j <= w; j++) {
            if (d[i][j]) {
                ans1 += (ans[i][j] == ans[i + 1][j]);
            }
            else {
                ans1 += (ans[i][j] != ans[i + 1][j]);
            }
        }
        ans[i + 1][1] = 2;
        for (int j = 1; j <= (w - 1); j++) {
            if (r[i + 1][j]) ans[i + 1][j + 1] = ans[i + 1][j];
            else ans[i + 1][j + 1] = 3 - ans[i + 1][j];
        }
        for (int j = 1; j <= w; j++) {
            if (d[i][j]) {
                ans2 += (ans[i][j] == ans[i + 1][j]);
            }
            else {
                ans2 += (ans[i][j] != ans[i + 1][j]);
            }
        }
        if (ans1 > ans2) {
            ans[i + 1][1] = 1;
        }
        for (int j = 1; j <= (w - 1); j++) {
            if (r[i + 1][j]) ans[i + 1][j + 1] = ans[i + 1][j];
            else ans[i + 1][j + 1] = 3 - ans[i + 1][j];
        }
    }
    cout << "YES" << '\n';
    if (!invert) {
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cout << ans[i][j] << " ";
            }
            cout << '\n';
        }
    }
    else {
        swap(w, h);
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cout << ans[j][i] << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}