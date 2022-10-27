#include<bits/stdc++.h>
using namespace std;
const int nax = 2048;
const int INF = 1e8;
int n, k;
char ans[nax][nax];
int mxipj = -INF;
int mnipj = INF;
int mximj = -INF;
int mnimj = INF;
array <int, 2> pos[nax * nax];

void fast_update(int i, int j) {
    mxipj = max(mxipj, i + j);
    mnipj = min(mnipj, i + j);
    mximj = max(mximj, i - j);
    mnimj = min(mnimj, i - j);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> k;

    for (int i = 1; i <= n ; ++ i)
    for (int j = 1 ; j <= n ; ++ j) {
        int x;
        cin >> x;
        pos[x] = {i, j};
    }

    for (int i = n * n; i >= 0 ; -- i) {
        auto [x, y] = pos[i];
        if (x + y - k > mnipj || x + y + k < mxipj
            || x - y - k > mnimj || x - y + k < mximj)
        {
            ans[x][y] = 'G';
        } else {
            ans[x][y] = 'M';
            fast_update(x, y);
        }
    }
    for (int i = 1 ; i <= n ; ++ i) {
        ans[i][n + 1] = '\0';
        cout << ans[i] + 1 << '\n';
    }
}