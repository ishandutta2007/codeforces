#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n, m, k;
const int maxN = 105;
int d[maxN];
char a[maxN][maxN];
int sz = 0;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(228);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    bool gC = false, cC = false;
    bool hasC = false;
    bool hasG = false;
    for (int i = 1; i <= n; i++) {
        int cntG = 0, cntC = 0;
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'G') cntG++;
            else if (a[i][j] == 'R') cntC++;
        }
        if (cntG == 1 && cntC == 1) {
            hasG = hasC = true;
            int aa = -1, bb = -1;
            for (int j = 1; j <= m; j++) {
                if (a[i][j] != '-' && aa == -1) aa = j;
                else if (a[i][j] != '-') bb = j;
            }
            sz++;
            d[sz] = bb - aa - 1;
        }
        else if (cntG != 0) {
            if (cntG != m) {
                hasG = true;
                gC = true;
            }
        }
        else if (cntC != 0) {
            if (cntC != m) {
                hasC = true;
                cC = true;
            }
        }
        else assert(cntC == 0 && cntG == 0);
    }
    if (gC && cC) {
        cout << "Draw";
        return 0;
    }
    if (!hasG) {
        cout << "Second";
        return 0;
    }
    if (!hasC) {
        cout << "First";
        return 0;
    }
    bool f = false;
    for (int i = 0; i < 20; i++) {
        int bt = 0;
        for (int j = 1; j <= sz; j++) {
            bt += (d[j] >> i) & 1;
            bt %= (k + 1);
        }
        if (bt != 0) {
            f = true;
            break;
        }
    }
    if (f) {
        if (cC) cout << "Draw";
        else cout << "First";
    }
    else {
        if (gC) cout << "Draw";
        else cout << "Second";
    }
    return 0;
}