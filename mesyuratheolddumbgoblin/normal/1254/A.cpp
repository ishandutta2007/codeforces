#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN (1<<20)
#define MOD 1000000007
#define N 1048576
ll n, x, k, z, m, pos, q, ans_v;
ll x1, p1, x2, p2;
ll a[105][105];
char ans[105][105];
vector<ll> f;

string pat;

void blyat() {
    for (char c = 'a'; c <= 'z'; c++) {
        pat.push_back(c);
    }

    for (char c = 'A'; c <= 'Z'; c++) {
        pat.push_back(c);
    }

    for (char c = '0'; c <= '9'; c++) {
        pat.push_back(c);
    }
}

void solve() {
    cin >> n >> m >> k;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == 'R') {
                a[i][j] = 1;
                sum++;
            } else {
                a[i][j] = 0;
            }
        }
    }

    ll lft = sum;
    ll curchick = 0;
    ll pshe = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ll pj = j;
            if (i % 2 == 0) {
                pj = m - 1 - j;
            }
            ans[i][pj] = pat[curchick];
            pshe += a[i][pj];
            if (pshe == lft / (k - curchick) && curchick != k-1) {
                lft -= lft / (k - curchick);
                curchick++;
                pshe = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j];
        }
        cout << "\n";
    }
}

int main() {
    blyat();
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}