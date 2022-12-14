/**
 *    author:  tourist
 *    created: 09.05.1945 00:43:00
**/
#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <ctime>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <complex>
#include <cstdint>
#include <fstream>
#include <forward_list>
#include <iomanip>

#define all(x) (x).begin(), (x).end()
#define re return
#define fi first
#define sz(x) (int)(x).size()
#define se second
#define mp make_pair
#define pb emplace_back
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define unq(x) { sort(x.begin(), x.end()); x.resize(unique (x.begin(), x.end()) - x.begin()); }

#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef complex<double> cmp;
typedef double D;
typedef vector<ii> vii;

const int MOD = 1e9 + 7;
const int N = 1e3 + 5;
const D PI = acos(-1);

mt19937 rnd(time(0));

int a[N][N], was[N][N], cnt, n, m;
vii v[N][N];

bool Ok(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y) {
    was[x][y] = 1;
    cnt++;
    for (auto& [nx, ny] : v[x][y]) {
        if (Ok(nx, ny) && !was[nx][ny]) {
            dfs(nx, ny);
        }
    }
}


void solve()
{
    cin >> n >> m;
    rep (i, n) {
        rep (j, m) {
            cin >> a[i][j];
            if (!(a[i][j] & 1)) {
                v[i][j].pb(i, j - 1);
            }
            if (!(a[i][j] & 2)) {
                v[i][j].pb(i + 1, j);
            }
            if (!(a[i][j] & 4)) {
                v[i][j].pb(i, j + 1);
            }
            if (!(a[i][j] & 8)) {
                v[i][j].pb(i - 1, j);
            }
        }
    }
    vi an;
    rep (i, n) {
        rep (j, m) {
            if (!was[i][j]) {
                cnt = 0;
                dfs(i, j);
                an.pb(cnt);
            }
        }
    }
    sort(all(an));
    reverse(all(an));
    for (int x : an) {
        cout << x << ' ';
    }
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen ("input.txt", "r", stdin);
//    freopen ("output.txt", "w", stdout);
    int qq = 1;
//    cin >> qq;
    rep(i, qq)
        solve();
}