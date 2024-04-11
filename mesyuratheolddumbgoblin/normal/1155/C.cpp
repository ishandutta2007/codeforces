#include <utility>
#include <bitset>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <time.h>
#include <iostream>
#include <vector>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 1000000007
typedef long long ll;
using namespace std;

ll a[300500], x, y, z, b[100500], n, m;
vector<pii> ans, f;
ll Abs(ll x) {
    return (x > 0 ? x : -x);
}
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a%b);
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll g = 0;
    for (int i = 0; i + 1 < n; i++) {
        if (g == 0)
            g = a[i+1] - a[i];
        g = gcd(g, a[i+1] - a[i]);
    }
    ll x;
    for (int i = 0; i < m; i++) {
        cin >> x;
        if (g % x == 0) {
            cout << "YES" << endl;
            cout << a[0] << " " << i + 1 << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}