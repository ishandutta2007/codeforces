#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int MX = 62, N = 32;

int n, a[N];
vector<pair<int, int>> ve;
bool dp[N][MX][MX * N], chk[MX][MX];

void solve(int u) {
    for (int i = u, j = n, cur = u * (u - 1) / 2; i >= 1; i--) {
        ve.push_back({a[j], i});
        cur -= a[j];
        if (!dp[j][i - 1][cur]) {
            --j;
        }
    }
    for (int i = 1; i <= u; i++) {
        sort(ve.begin(), ve.end());
        for (int j = 0; j < (int)ve.size() - 1; j++) {
            if (j < ve.back().fi) {
                chk[ve.back().se][ve[j].se] = true;
            } else {
                chk[ve[j].se][ve.back().se] = true;
                ve[j].fi--;
            }
        }
        ve.pop_back();
    }
    cout << u << '\n';
    for (int i = 1; i <= u; i++, cout << '\n') {
        for (int j = 1; j <= u; j++) {
            cout << chk[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    dp[0][0][0] = true;
    for (int st = 1; st < MX; st++) {
        for (int su = st * (st - 1) / 2; su < MX * N; su++) {
            for (int i = 1; i <= n; i++) {
                if (su >= a[i]) {
                    dp[i][st][su] = dp[i][st - 1][su - a[i]] | dp[i - 1][st - 1][su - a[i]];
                }
            }
        }
        if (dp[n][st][st * (st - 1) / 2]) {
            solve(st);
            return 0;
        }
    }
    cout << "=(";
}