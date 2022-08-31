#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 65;
int m;
int a[maxN];
bool dp[(maxN * maxN) / 2][maxN][maxN];
int prv[(maxN * maxN) / 2][maxN][maxN];
int s[maxN][maxN];
void go(int v) {
    vector < pair < int, int > > degs;
    int sm = (v * (v - 1)) / 2;
    int cnt = v;
    int pos = m;
    while (pos > 0) {
        int x = prv[sm][cnt][pos];
        for (int i = 1; i <= x; i++) {
            degs.emplace_back(a[pos], cnt);
            sm -= a[pos];
            cnt--;
        }
        pos--;
    }
    reverse(degs.begin(), degs.end());
    while (!degs.empty()) {
        sort(degs.begin(), degs.end());
        int d = degs.back().first;
        for (int j = 0; j + 1 < degs.size(); j++) {
            if (j < d) {
                s[degs.back().second][degs[j].second] = 1;
            }
            else {
                s[degs[j].second][degs.back().second] = 1;
                degs[j].first--;
            }
        }
        degs.pop_back();
    }
    cout << v << '\n';
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            cout << s[i][j];
        }
        cout << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + m + 1);
    dp[0][0][0] = true;
    int lim = 62;
    for (int cnt = 0; cnt + 1 <= lim; cnt++) {
        for (int where = 0; where + 1 <= m; where++) {
            for (int sm = (cnt * (cnt - 1)) / 2; sm <= cnt * a[m]; sm++) {
                if (!dp[sm][cnt][where]) continue;
                int nsm = sm;
                int ncnt = cnt;
                for (int add = 1; add + cnt <= lim; add++) {
                    nsm += a[where + 1];
                    ncnt++;
                    if (nsm < (ncnt * (ncnt - 1)) / 2) break;
                    dp[nsm][ncnt][where + 1] = true;
                    prv[nsm][ncnt][where + 1] = add;
                }
            }
        }
    }
    for (int i = 0; i <= lim; i++) {
        if (dp[(i * (i - 1)) / 2][i][m]) {
            go(i);
            return 0;
        }
    }
    cout << "=(";
    return 0;
}