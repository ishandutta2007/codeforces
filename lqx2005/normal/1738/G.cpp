#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define vi vector<int>
#define pr pair<int, int>
using namespace std;
const int N = 1e3 + 10;
int n, k;
int a[N][N], b[N][N], dp1[N][N], dp2[N][N], dp3[N][N], dp4[N][N];
void solve() {
    cin >> n >> k;
    vector<pair<int, int>> ord;
    FOR(i, 0, n + 1) FOR(j, 0, n + 1) dp1[i][j] = dp2[i][j] = dp3[i][j] = 0;
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            ord.emplace_back(i, j);
            char x;
            cin >> x;
            a[i][j] = x - '0';
            b[i][j] = 1;
        }
    }
    sort(ord.begin(), ord.end(), [&](pr a, pr b) {
        return a.first + a.second > b.first + b.second;
    });
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            dp1[i][j] = dp2[i - 1][j - 1] + !a[i][j];
            dp2[i][j] = max(dp2[i - 1][j], dp2[i][j - 1]);
            dp2[i][j] = max(dp2[i][j], dp1[i][j]);
        }
    }
    if(dp2[n][n] >= k) return cout << "NO\n", void();
    int cnt = 0;
    for(auto [i, j] : ord) {
        if(a[i][j]) {
            if(dp4[i + 1][j + 1] + 1 + dp2[i - 1][j - 1] < k) {
                b[i][j] = 1;
            } else b[i][j] = 0, cnt++;
        }
        dp3[i][j] = dp4[i + 1][j + 1] + b[i][j];
        dp4[i][j] = max({dp3[i][j], dp4[i + 1][j], dp4[i][j + 1]});
    }
    int aim = (n - k + 1) * (n - k + 1);
    if(cnt > aim) return cout << "NO\n", void();
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            if(a[i][j] && b[i][j] && cnt < aim) {
                b[i][j] = 0;
                cnt++;
            }
        }
    }
    if(cnt < aim) return cout << "NO\n", void();
    cout << "YES\n";
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            cout << b[i][j];
        }
        cout << "\n";
    }
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; ) solve();
    return 0;
}