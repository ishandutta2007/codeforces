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

bool Nice(int n, int m, D p) {
    int call = n * (n - 1) * (n - 2) / 6;
    int c111 = m * (m - 1) * (m - 2) / 6;
    int c011 = m * (m - 1) * (n - m) / 2;
    int c001=  m * (n - m) * (n - m - 1) / 2;
    D an = (D)(c111 + c011) / call + (D)c001 / (call * 2);
    if (abs(an - p) < 1e-9) {
        re 1;
    }
    if (an > p) {
        re 1;
    }
    re 0;
}

void solve()
{
    int n;
    D p;
    cin >> n >> p;

    rep(i, n) {
        if (Nice(n, i, p)) {
            cout << i;
            re;
        }
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