
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 35;
int t, n, m, a[N][N], cnt[2][2 * N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        rep(i, 0, n + m) {
            cnt[0][i] = cnt[1][i] = 0;
        }
        rep(i, 0, n) rep(j, 0, m) {
            cin >> a[i][j];
            cnt[a[i][j]][i + j]++;
        }
        int ans = 0;
        rep(i, 0, (n + m - 1) / 2) {
            ans += min(cnt[0][i] + cnt[0][n + m - 2 - i], cnt[1][i] + cnt[1][n + m - 2 - i]);
        }
        cout << ans << '\n';
    }
}