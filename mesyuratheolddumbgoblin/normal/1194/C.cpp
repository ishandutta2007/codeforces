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

#define MOD 1000000007
#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef int ll;
using namespace std;
ll n, m, k, x, y, z, q;
ll a[500500], cc[500500];
vector<vector<ll> > b;
void solve() {

    string s, t, p;
    cin >> s >> t >> p;
    int r = 0;
    for (int i = 0; i < s.size(); i++) {
        while (r < t.size() && s[i] != t[r]) {
            r++;
        }
        if (r == t.size()) {
            cout << "NO" << endl;
            return;
        }
        r++;
    }
    for (char c = 'a' ; c <= 'z'; c++) {
        a[c] = 0;
    }
    for (auto c : s) {
        a[c]--;
    }
    for (auto c : t) {
        a[c]++;
    }
    for (auto c : p) {
        a[c]--;
    }
    for (char c = 'a' ; c <= 'z'; c++) {
        if (a[c] > 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}
int main() {
    ll m;
    cin >> m;
    while (m--) {
        solve();
    }
    return 0;
}