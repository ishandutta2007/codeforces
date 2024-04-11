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

//#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef complex<double> cmp;
typedef double D;
typedef vector<ii> vii;

const int MOD = 1e9 + 7;
const int N = 50 + 5;
const D PI = acos(-1);

mt19937 rnd(time(0));

int n, m;
int a[N][N];

vi v;
int last = -1;

void Go (int pos) {
    if (pos == 5) {
        int cnt = 0;
        rep (i, 5) {
            for (int j = i + 1; j < 5; j++) {
                cnt += a[v[i]][v[j]];
            }
        }
        if (!cnt || cnt == 10) {
            for (int x : v) {
                cout << x + 1 << ' ';
            }
            exit(0);
        }
        re;
    }
    for (int i = last + 1; i < min(n, 48); i++) {
        v.pb(i);
        int l = last;
        last = i;
        Go(pos + 1);
        last = l;
        v.pop_back();
    }

}


void solve()
{
    cin >> n >> m;
    rep (i, m) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        if (l < 48 && r < 48) {
            a[l][r] = 1;
            a[r][l] = 1;
        }
    }
    Go(0);
    cout << -1;
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