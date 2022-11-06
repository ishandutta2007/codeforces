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
map<ll, ll> g[600500];
ll a[600500], b[600500], p[600500];


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= 10000; i++) {
        if (n - i * k < i) {
            break;
        }
        ll x = 0;
        for (int j = 30; j >= 0; j--) {
            if (((n - i * k) >> j) & 1) {
                x++;
            }
        }
        if (x <= i) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}