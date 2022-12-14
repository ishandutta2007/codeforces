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


void solve()
{
    cout << "? 1 1" << endl;
    int d;
    cin >> d;
    int L = 2, R = 1000000000;
    while (R - L > 1) {
        int M = (L + R) / 2;
        cout << "? " << M << " 1" << endl;
        int cd;
        cin >> cd;
        if (cd != d - M + 1) {
            R = M;
        }
        else {
            L = M;
        }
    }
    int x1 = L, y1 = d - L + 2;
    cout << "? 1 1000000000" << endl;
    int cd;
    cin >> cd;
    int y2 = 1000000000 + x1 - cd - 1;
    cout << "? 1000000000 1" << endl;
    cin >> cd;
    int x2 = 1000000000 + y1 - cd - 1;
    cout << "! " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
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