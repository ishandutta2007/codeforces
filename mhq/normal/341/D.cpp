#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1005;
int n, m;
ll f[2][2][maxN][maxN];
void upd(int x, int y, ll v) {
    int f1 = x % 2;
    int f2 = y % 2;
    for (int i = x; i <= n; i = (i | (i - 1)) + 1) {
        for (int j = y; j <= n; j = (j | (j - 1))+ 1) {
            f[f1][f2][i][j] ^= v;
        }
    }
}
ll get_rect(int x, int y) {
    // a[k][l] = xor vseh do nego (n - k + 1)(m - l + 1) raz
    int f1 = x % 2;
    int f2 = y % 2;
    ll ans = 0;
    while (x > 0) {
        int r = y;
        while (r > 0) {
            ans ^= f[f1][f2][x][r];
            r = r & (r - 1);
        }
        x = x & (x - 1);
    }
    return ans;
}
void query() {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << (get_rect(x2, y2) ^ get_rect(x1 - 1, y2) ^ get_rect(x2, y1 - 1) ^ get_rect(x1 - 1, y1 - 1)) << '\n';
    // b[x][y] = a[x][y] ^ a[x - 1][y] ^ a[x][y - 1] ^ a[x - 1][y - 1]
}
void update() {
    int x1, x2, y1, y2;
    ll v;
    cin >> x1 >> y1 >> x2 >> y2 >> v;
    upd(x1, y1, v);
    upd(x2 + 1, y1, v);
    upd(x1, y2 + 1, v);
    upd(x2 + 1, y2 + 1, v);
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int type;
        cin >> type;
        if (type == 1) query();
        else update();
    }
	return 0;
}