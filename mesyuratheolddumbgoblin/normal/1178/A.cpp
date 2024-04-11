#include <sstream>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <map>
#include <set>

#define MOD 998244353
#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
ll a[200500], b[200500];
ll n, m, i, j, k, x, y, z;
vector<ll> f;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        k += a[i];
    }
    x += a[0];
    f.push_back(0);
    for (int i = 1; i < n; i++) {
        if (a[i] * 2 <= a[0]) {
            x += a[i];
            f.push_back(i);
        }
    }
    if (x * 2 > k) {
        cout << f.size() << endl;
        for (auto x : f) {
            cout << x + 1 << " ";
        }
    } else {
        cout << 0 << endl;
    }
    return 0;
}