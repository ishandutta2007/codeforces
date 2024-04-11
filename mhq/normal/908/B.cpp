#include <bits/stdc++.h>
using namespace std;
char a[55][55];
int n, m;
string s;
int b[4];
int xs, ys, xf, yf;
bool check() {
    int curx = xs;
    int cury = ys;
    for (int i = 0; i < s.size(); i++) {
        int v = s[i] - '0';
        if (b[v] == 0) {
            curx++;
        }
        if (b[v] == 1) {
            curx--;
        }
        if (b[v] == 2) {
            cury++;
        }
        if (b[v] == 3) {
            cury--;
        }
        if (a[curx][cury] == '#') return false;
        if (a[curx][cury] == 'E') return true;
        if (curx >= n || curx < 0) return false;
        if (cury >= m || cury < 0) return false;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') {
                xs = i;
                ys = j;
            }
            if (a[i][j] == 'E') {
                xf = i;
                yf = j;
            }
        }
    }
    cin >> s;
    int a[4];
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    int ans = 0;
    do {
        for (int i = 0; i < 4; i++) b[i] = a[i];
        if (check()) ans++;
    } while (next_permutation(a, a + 4));
    cout << ans;
    return 0;
}