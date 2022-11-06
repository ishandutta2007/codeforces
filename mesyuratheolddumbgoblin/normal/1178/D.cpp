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
vector<pii> f;
bool solve(ll n) {
    ll k = 0;
    f.clear();
    for (int i = 0; i < n; i++) {
        f.push_back(mp(i, (i+1)%n));
        k++;
    }
    if (a[k]) {
        return true;
    }
    for (int i = 0; i < n/2; i++) {
        f.push_back(mp(i, (i+n/2) % n));
        k++;
        if (a[k]) {
            return true;
        }
    }
    return false;
}
int main() {
    for (int i = 2; i <= 5005; i++) {
        a[i] = 1;
    }
    for (int i = 2; i <= 5005; i++) {
        if (a[i]) {
            for (int j = i * 2; j <= 5005; j+=i) {
                a[j] = 0;
            }
        }
    }

    cin >> n;
    bool k = solve(n);
    if (k) {
        cout << f.size() << endl;
        for (auto x : f) {
            cout << x.X + 1 << " " << x.Y + 1 << endl;
        }
    } else {
        cout << "14/88" << endl;
    }
    return 0;
}