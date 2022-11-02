#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pi> vpi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define mp make_pair
#define F first
#define S second

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll MOD = 1e9+7;// 998244353;

int t, n, m, k, total;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
vector<vector<char>> grid;

void place(int a, int b, int c, int d) {
    set<char> taken;
    F0R(i, 4) {
        if (a+dx[i]<0 || a+dx[i]>=n || b+dy[i]<0 || b+dy[i]>=m) ;
        else taken.insert(grid[a+dx[i]][b+dy[i]]);
        if (c+dx[i]<0 || c+dx[i]>=n || d+dy[i]<0 || d+dy[i]>=m) ;
        else taken.insert(grid[c+dx[i]][d+dy[i]]);
    }
    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (taken.count(ch)==0) {
            grid[a][b]=grid[c][d]=ch;
            return;
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    grid.clear(); grid.rsz(n, vector<char>(m, '0'));
    total = (n*m)/2;
    if (n%2 != 0) {
        for (int i = 0; i < m; i += 2) place(n-1, i, n-1, i+1);
        k -= m/2;
    }
    if (m%2 != 0) {
        for (int i = 0; i < n; i += 2) place(i, m-1, i+1, m-1);
        total -= n/2;
    }
    if (k<0 || k>total || k%2 != 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int x=0, y=0;
    F0R(i, k) {
        if (x >= n - n%2) {
            x=0;
            y += 2;
        }
        place(x, y, x, y+1);
        x++;
    }
    FOR(j, y, m - m%2) {
        if (j<y+2) {
            for (int i = x; i < n-1; i += 2) place(i, j, i+1, j);
        } else {
            for (int i = 0; i < n-1; i += 2) place(i, j, i+1, j);
        }
    }
    F0R(i, n) {
        F0R(j, m) cout << grid[i][j];
        cout << '\n';
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}