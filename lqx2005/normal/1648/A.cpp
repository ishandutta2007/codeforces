#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define sz(a) int((a).size())
#define vi vector<int>
typedef long long ll;
typedef double db;
const int N = 1e5 + 10;
int n, m;
vector<pair<int, int>> c[N];
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) for(int j = 1, x; j <= m; j++) {
        cin >> x;
        c[x].emplace_back(i, j);
    }
    int v = 1e5;
    ll ans = 0;
    for(int i = 1; i <= v; i++) {
        for(int j = 1; j < sz(c[i]); j++) {
            if(c[i][j - 1].x != c[i][j].x) {
                ans += (ll)(c[i][j].x - c[i][j - 1].x) * j * (sz(c[i]) - j);
            }
        }
        sort(c[i].begin(), c[i].end(), [&](pair<int, int> a, pair<int, int> b) {
            return a.y < b.y;
        });
        for(int j = 1; j < sz(c[i]); j++) {
            if(c[i][j - 1].y != c[i][j].y) {
                ans += (ll)(c[i][j].y - c[i][j - 1].y) * j * (sz(c[i]) - j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}