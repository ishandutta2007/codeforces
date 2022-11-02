#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstring>

using namespace std;

const int maxn = 105;
const int maxk = 30;

int n, k;
int tro[maxk], tl[maxk], tr[maxk], cnt;
int sro;

bool good[maxn][3];

bool nocrash(int c, int r, int t) {
    for (int i = 0; i < k; i++)
        if (!(r != tro[i] || c < tl[i] - 2*t || c > tr[i] - 2*t))
            return 0;
    return 1;
}

void go() {
    cin >> n >> k;
    cnt = 0;
    for (int i = 0; i < 3; i++) {
        char cur = 0;
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            if (c != cur && cur != 0) tr[cnt] = j-1, cnt++, cur = 0;
            if (c == 's') sro = i;
            else if (c != '.') {
                if (cur == 0) tro[cnt] = i, tl[cnt] = j, cur = c;
            }
        }
        if (cur != 0) tr[cnt] = n-1, cnt++, cur = 0;
    }

    assert(cnt == k);

    memset(good, 0, sizeof(good));
    good[0][sro] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            if (good[i][j] && nocrash(i+1, j, i)) {
                for (int dr=-1; dr<=1; dr++)
                    if (j+dr >= 0 && j+dr < 3)
                        if (nocrash(i+1, j+dr, i) && nocrash(i+1, j+dr, i+1))
                            good[i+1][j+dr] = 1;
            }

    if (good[n][0] || good[n][1] || good[n][2]) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    int t; cin >> t;
    while (t--) go();
}