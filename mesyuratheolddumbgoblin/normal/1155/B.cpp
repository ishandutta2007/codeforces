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
typedef int ll;
using namespace std;

ll a[100500], x, y, z, b[100500], n, m;
vector<pii> ans, f;
ll Abs(ll x) {
    return (x > 0 ? x : -x);
}
int main() {
    cin >> n;
    string s;
    cin >> s;
    ll k = 0;
    for (int i = 0; i < n - 10; i++) {
        if (s[i] == '8') {
            k++;
        }
    }
    if (k > n - 10 - k) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}