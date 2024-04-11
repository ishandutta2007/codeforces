#include <bits/stdc++.h>
using namespace std;

const int N = 50004, K = 101;

int n, f[N][K], nxt[N][26];
bool chk[N][K];
char s[N];
string lef = "", mid = "";

int main() {
    cin >> (s + 1);
    n = strlen(s + 1);
    fill(nxt[n + 2], nxt[n + 2] + 26, n + 1);
    fill(nxt[n + 1], nxt[n + 1] + 26, n + 1);
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < 26; j++) {
            nxt[i][j] = nxt[i + 1][j];
        }
        nxt[i][s[i] - 'a'] = i;
    }
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 2; j < K; j++) {
            f[i][j] = n + 1;
        }
        f[i][0] = i - 1;
        f[i][1] = i;
        chk[i][1] = true;
    }
    for (int l = n; l >= 1; l--) {
        for (int i = 2; i < K; i++) {
            int cur = f[l + 1][i - 2] + 1;
            int tmp = nxt[cur][s[l] - 'a'];
            if (tmp < f[l][i]) {
                f[l][i] = tmp;
                chk[l][i] = true;
            }
            if (f[l + 1][i] < f[l][i]) {
                f[l][i] = f[l + 1][i];
                chk[l][i] = false;
            }
        }
    }
    int cur = 0;
    for (int i = 1; i < K; i++) {
        if (f[1][i] <= n) {
            cur = i;
        }
    }
    for (int i = 1; i <= n && cur > 0; i++) {
        if (chk[i][cur]) {
            if (cur >= 2) {
                lef += s[i];
            } else {
                mid += s[i];
            }
            cur -= 2;
        }
    }
    cout << lef << mid;
    reverse(lef.begin(), lef.end());
    cout << lef;
}