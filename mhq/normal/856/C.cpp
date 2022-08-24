#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
vector<int> x[2];
int t, n, a;
int f[2007][2007][11];
int g[2007][2007][11];
int fact[2007];
int len (int a){
    int i = 0;
    while (a > 0) {
        a = a / 10;
        i++;
    }
    return i;
}
void fact1() {
    fact[0] = 1;
    for ( int j = 1; j <= 2001; j++ )
        fact[j] = (1ll * fact[j - 1] * j) % mod;

}
void read() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        x[len(a) % 2].push_back(a % 11);
    }
}
void add(int &x, int q) {
    x += q;
    if ( x >= mod ) x -= mod;
}
int sum ( int x, int y) {
    x += y;
    if ( x >= 11 ) x -= 11;
    return x;
}
int mult ( int x, int y ) {
    return (1ll * x * y) % mod;
}
void clear1() {
    x[0].clear(); x[1].clear();
    for ( int i = 0; i <= n + 2; i++) {
        for ( int j = 0; j <= n + 2; j++) {
            for (int ost = 0; ost <= 10; ost++) {
                f[i][j][ost] = 0;
                g[i][j][ost] = 0;
            }
        }
    }
}
void solve() {
    f[0][0][0] = 1;
    for ( int i = 0; i < x[1].size(); i++) {
        int cur = x[1][i];
        for ( int j = 0; j <= i; j++) {
            for ( int ost = 0; ost < 11; ost++) {
                add(f[i + 1][j + 1][sum(ost, cur)], f[i][j][ost]);
                add(f[i + 1][j][sum(ost, 11 - cur)], f[i][j][ost]);
            }
        }
    }
    int u = (x[1].size()) / 2 + 1;
    int r = x[1].size() + 1 - u;
    for ( int ost = 0; ost <= 10; ost++) {
        f[x[1].size()][(x[1].size() + 1) / 2][ost] = mult( mult( f[x[1].size()][(x[1].size() + 1) / 2][ost], fact[(x[1].size() + 1)/2]), fact[x[1].size() - (x[1].size() + 1) / 2]);
    }
    g[0][0][0] = 1;
    for ( int i = 0; i < x[0].size(); i++) {
        int cur = x[0][i];
        for ( int j = 0; j <= i; j++) {
            for ( int ost = 0; ost < 11; ost++) {
                add(g[i + 1][j + 1][sum(ost, cur)], mult(g[i][j][ost], u + j));
                add(g[i + 1][j][sum(ost, 11 - cur)], mult(g[i][j][ost], r  + i - j));
            }
        }
    }
    int ans = 0;
    for ( int ost = 0; ost <= 10; ost++) {
        for ( int j = 0; j <= x[0].size(); j++)
            add(ans, mult( f[x[1].size()][(x[1].size() + 1) / 2 ][ost], g[x[0].size()][j][sum(11 - ost, 0)]));
    }
    cout << ans << endl;
    clear1();
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> t;
    fact1();
    for (; t >= 1; t--) {
        read();
        solve();
    }
}