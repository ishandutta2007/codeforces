
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

// path of length (n - 1) + (m - 1)

const int N = 21;
int n, m;
ll k, a[N][N];
map<ll, int> ma[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    rep(i, 0, n) rep(j, 0, m) {
        cin >> a[i][j];
    }
    int len = (n - 1) + (m - 1);
    int path = len / 2;
    rep(mask, 0, 1 << path) {
        int x = 0, y = 0;
        ll val = 0;
        rep(i, 0, path) {
            if(x >= n || y >= m) break;
            val ^= a[x][y];
            (((mask >> i) & 1) ? x : y)++;
        }
        if(x < n && y < m) {
            ma[x][y][val]++;
        }
    }
    ll ans = 0;
    rep(mask, 0, 1 << (len - path)) {
        int x = n - 1, y = m - 1;
        ll val = k;
        rep(i, 0, len - path) {
            if(x < 0 || y < 0) break;
            val ^= a[x][y];
            (((mask >> i) & 1) ? x : y)--;
        }
        if(x >= 0 && y >= 0) {
            val ^= a[x][y];
            ans += ma[x][y][val];
        }
    }
    cout << ans << endl;
}