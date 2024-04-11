#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 510;
int t[maxN];
bool was[maxN][maxN][35][8];
bool has[maxN][maxN];
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1,  1, 0,  -1, -1, -1};
int n;
void dfs(int a, int b, int dir, int pos) {
    //cout << a << " " << b << " " << dir << " " << pos << endl;
    if (pos == n) return ;
    if (was[a][b][pos][dir]) return ;
    was[a][b][pos][dir] = true;
    has[a][b] = true;
    for (int k = 1; k + (pos == 0) <= t[pos]; k++) {
        a += dx[dir];
        b += dy[dir];
        has[a][b] = true;
    }
    dfs(a, b, (dir + 1) % 8, pos + 1);
    dfs(a, b, (dir + 7) % 8, pos + 1);
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    dfs(250, 250, 0, 0);
    int ans = 0;
    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 500; j++) {
            if (has[i][j]) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}